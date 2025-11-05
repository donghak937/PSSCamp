using System;
using System.Globalization;

namespace AuctionTurnBattle
{
    class Program
    {
        static void Main()
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Console.WriteLine("=== ⚔️ 1대1 경매 시뮬레이터 (턴 기반, 정규분포 AI) ===\n");

            // ===== 1) 기본 입력 =====
            int start = ReadInt("입찰 시작가(원)            : ");
            int trueV = ReadInt("시장가(원)                 : ");
            double centerT = ReadDouble("AI 중심 위치(0~1, 0=시작가, 1=시장가*1.2) : ", 0, 1);
            int spreadLevel = ReadInt("AI 퍼짐 레벨(1=좁음 ~ 10=넓음) : ", 1, 10);
            int roundingUnit = ReadInt("반올림 단위(예: 1000)        : ", 1, int.MaxValue);

            double hi = trueV * 1.2;
            double range = hi - start;
            double mean = Lerp(start, hi, centerT);
            double sigmaRatio = LogLerp(0.03, 0.35, (spreadLevel - 1) / 9.0);
            double sigma = Math.Max(1.0, range * sigmaRatio);

            var rng = new Random(Guid.NewGuid().GetHashCode());
            double aiTarget = SampleTruncatedNormal(mean, sigma, start, hi, rng);
            aiTarget = RoundToUnit(aiTarget, roundingUnit);
            aiTarget = Clamp(aiTarget, start, hi);

            Console.WriteLine($"\n🤖 AI가 내부적으로 설정한 목표가: {aiTarget:N0}원 (비공개)");
            Console.WriteLine("\n💰 경매 시작!\n");

            // ===== 2) 경매 루프 =====
            int currentBid = start;
            bool playerTurn = true;
            bool auctionEnded = false;

            while (!auctionEnded)
            {
                if (playerTurn)
                {
                    Console.WriteLine($"현재 입찰가: {currentBid:N0}원");
                    int playerBid = ReadInt("당신의 입찰가를 입력하세요(0 입력 시 포기): ", 0, (int)hi);

                    if (playerBid == 0)
                    {
                        Console.WriteLine("🙋‍♂️ 플레이어가 포기했습니다!");
                        Console.WriteLine($"🏦 최종 낙찰자: 🤖 AI (입찰가 {currentBid:N0}원)");
                        break;
                    }

                    if (playerBid <= currentBid)
                    {
                        Console.WriteLine("  ↳ 이전 입찰가보다 높게 불러야 합니다!\n");
                        continue;
                    }

                    currentBid = playerBid;
                    playerTurn = false;
                }
                else
                {
                    Console.WriteLine("🤖 컴퓨터의 차례입니다...");
                    System.Threading.Thread.Sleep(1000);

                    // AI 입찰 로직
                    if (currentBid >= aiTarget)
                    {
                        Console.WriteLine("🤖 AI: “그건 너무 비싸네요... 포기합니다.”");
                        Console.WriteLine($"🎉 최종 낙찰자: 🧑‍💼 플레이어 (입찰가 {currentBid:N0}원)");
                        auctionEnded = true;
                    }
                    else
                    {
                        // AI는 “플레이어 입찰가 + 시작가의 20%” 만큼 부름
                        double aiNext = currentBid + start * 0.2;

                        // 목표 금액보다 높아지면 바로 포기
                        if (aiNext > aiTarget)
                        {
                            Console.WriteLine($"🤖 AI: “그 이상은 무리네요...” (목표가 {aiTarget:N0}원)");
                            Console.WriteLine($"🎉 최종 낙찰자: 🧑‍💼 플레이어 (입찰가 {currentBid:N0}원)");
                            auctionEnded = true;
                        }
                        else
                        {
                            aiNext = RoundToUnit(aiNext, roundingUnit);
                            aiNext = (int)Clamp(aiNext, start, hi);
                            Console.WriteLine($"🤖 AI가 {aiNext:N0}원을 불렀습니다!");
                            currentBid = (int)aiNext;
                            playerTurn = true;
                        }
                    }
                }
            }

            Console.WriteLine("\n=== 경매 종료 ===");
            Console.WriteLine($"최종 입찰가: {currentBid:N0}원");
            Console.WriteLine($"AI 목표가: {aiTarget:N0}원");
        }

        // === 유틸 ===
        static int ReadInt(string prompt, int min = int.MinValue, int max = int.MaxValue)
        {
            while (true)
            {
                Console.Write(prompt);
                string s = Console.ReadLine()?.Trim();
                if (int.TryParse(s, out int v) && v >= min && v <= max) return v;
                Console.WriteLine("  ↳ 정수를 올바르게 입력하세요.");
            }
        }

        static double ReadDouble(string prompt, double min, double max)
        {
            while (true)
            {
                Console.Write(prompt);
                string s = Console.ReadLine()?.Trim();
                if (double.TryParse(s, NumberStyles.Float, CultureInfo.InvariantCulture, out double v) && v >= min && v <= max) return v;
                Console.WriteLine("  ↳ 실수를 올바르게 입력하세요.");
            }
        }

        static double Lerp(double a, double b, double t) => a + (b - a) * t;

        static double LogLerp(double a, double b, double t)
        {
            double la = Math.Log(a);
            double lb = Math.Log(b);
            return Math.Exp(la + (lb - la) * t);
        }

        static double Clamp(double x, double lo, double hi) => Math.Max(lo, Math.Min(hi, x));

        static double RoundToUnit(double x, int unit)
        {
            if (unit <= 1) return Math.Round(x);
            return Math.Round(x / unit) * unit;
        }

        // === 정규분포 샘플 ===
        static double SampleStdNormal(Random rng)
        {
            double u1 = 1.0 - rng.NextDouble();
            double u2 = 1.0 - rng.NextDouble();
            return Math.Sqrt(-2.0 * Math.Log(u1)) * Math.Cos(2 * Math.PI * u2);
        }

        static double SampleNormal(double mean, double sigma, Random rng)
        {
            return mean + sigma * SampleStdNormal(rng);
        }

        static double SampleTruncatedNormal(double mean, double sigma, double lo, double hi, Random rng, int maxTries = 1000)
        {
            for (int i = 0; i < maxTries; i++)
            {
                double x = SampleNormal(mean, sigma, rng);
                if (x >= lo && x <= hi) return x;
            }
            return Clamp(mean, lo, hi);
        }
    }
}
