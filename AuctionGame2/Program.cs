using System;
using System.Globalization;

namespace AuctionGameSoloAI
{
    class Program
    {
        static void Main()
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            Console.WriteLine("=== 경매 게임 (플레이어 1회 입력 → 5틱은 AI만 진행) ===");
            int start = ReadInt("시작 가격(원): ");
            int trueV = ReadInt("진짜 가격/시장가(원): ");
            double aggr = ReadDouble("AI 호전성(0~10): ", 0, 10);

            var prm = Params.FromAggressiveness(aggr);
            var rng = new Random(); // 필요시 seed 고정 가능
            var game = new AuctionGame(prm, rng);

            game.Run(start, trueV);
        }

        static int ReadInt(string label)
        {
            while (true)
            {
                Console.Write(label);
                var s = Console.ReadLine();
                if (int.TryParse(s, NumberStyles.Integer, CultureInfo.InvariantCulture, out var v) && v >= 0)
                    return v;
                Console.WriteLine("정수를 입력하세요 (0 이상).");
            }
        }

        static double ReadDouble(string label, double min, double max)
        {
            while (true)
            {
                Console.Write(label);
                var s = Console.ReadLine();
                if (double.TryParse(s, NumberStyles.Float, CultureInfo.InvariantCulture, out var v) && v >= min && v <= max)
                    return v;
                Console.WriteLine($"{min} ~ {max} 범위의 숫자를 입력하세요.");
            }
        }
    }

    // ===== 파라미터 / 난이도 맵핑 =====
    public class Params
    {
        public double A;         // 가격 민감도 (낮을수록 공격적)
        public double Lambda;    // 최저 참여도
        public double Gamma;     // 막판 가속
        public double T = 10;    // 총 10초
        public int    MinStep;   // 최소 호가
        public double Eta;       // v 이하에서 남은 차이 비율
        public double EtaAbove;  // v 이상에서 v 비율
        public double Tau;       // v 이상 꼬리 스케일(오버페이 허용)
        public double Beta;      // v 이상 감쇠(낮을수록 꼬리 두꺼움)

        public static Params FromAggressiveness(double g)
        {
            // 보수형(0) ~ 공격형(10) 사이 보간
            var cons = new Params {
                A=3.4, Lambda=0.08, Gamma=2.8,
                MinStep=1000, Eta=0.18, EtaAbove=0.04,
                Tau=0.20, Beta=2.0
            };
            var aggr = new Params {
                A=1.8, Lambda=0.35, Gamma=2.2,
                MinStep=2500, Eta=0.50, EtaAbove=0.15,
                Tau=1.00, Beta=0.8
            };
            double t = g / 10.0;
            return new Params {
                A = Lerp(cons.A, aggr.A, t),
                Lambda = Lerp(cons.Lambda, aggr.Lambda, t),
                Gamma = Lerp(cons.Gamma, aggr.Gamma, t),
                MinStep = (int)Math.Round(Lerp(cons.MinStep, aggr.MinStep, t)),
                Eta = Lerp(cons.Eta, aggr.Eta, t),
                EtaAbove = Lerp(cons.EtaAbove, aggr.EtaAbove, t),
                Tau = Lerp(cons.Tau, aggr.Tau, t),
                Beta = Lerp(cons.Beta, aggr.Beta, t),
                T = 10
            };
        }
        private static double Lerp(double a, double b, double t) => a + (b - a) * t;
    }

    // ===== 게임 엔진 (플레이어 1회 입력 → AI 5틱만 진행) =====
    public class AuctionGame
    {
        private readonly Params _p;
        private readonly Random _rng;
        private static readonly double[] TickSeconds = { 2, 4, 6, 8, 10 };

        public AuctionGame(Params p, Random rng)
        {
            _p = p;
            _rng = rng;
        }

        public void Run(int startPrice, int trueValue, int maxRounds = 100)
        {
            int price = startPrice;
            int round = 1;
            int? playersBidThisRound = null;      // 플레이어가 이번 라운드에 부른 금액(없으면 null)
            string lastBidder = "없음";

            Console.WriteLine($"\n시장가: {trueValue:N0}원");
            Console.WriteLine($"최소 호가단위: {_p.MinStep:N0}원");
            Console.WriteLine("규칙: 라운드마다 플레이어는 단 1회만 입찰 입력(또는 패스). 그 다음 5틱은 AI만 진행.");
            Console.WriteLine("      AI가 플레이어가 부른 금액 '이상(≥)'으로 입찰하면 AI 승 → 다음 라운드(타이머 리셋).");
            Console.WriteLine("      한 라운드의 5틱 모두 AI가 패스하면 경매 종료.\n");

            while (round <= maxRounds)
            {
                Console.WriteLine($"\n=== 라운드 {round} 시작 (현재가 {price:N0}원) ===");

                // 1) 플레이어는 이번 라운드에 한 번만 부를 기회
                int minAllowed = price + _p.MinStep;
                Console.Write($"플레이어 입찰(엔터=패스, 최소 {minAllowed:N0} 이상 입력): ");
                var input = Console.ReadLine();
                if (!string.IsNullOrWhiteSpace(input))
                {
                    if (int.TryParse(input.Replace(",", ""), out var playerBid) && playerBid >= minAllowed)
                    {
                        price = playerBid;
                        playersBidThisRound = playerBid;
                        lastBidder = "플레이어";
                        Console.WriteLine($"→ 플레이어가 {price:N0}원에 입찰!");
                    }
                    else
                    {
                        Console.WriteLine("입찰 무시: 최소 허용가 이상 정수로 입력하세요. (이번 라운드 플레이어는 패스 처리)");
                        playersBidThisRound = null;
                    }
                }
                else
                {
                    playersBidThisRound = null; // 패스
                }

                // 2) 이번 라운드의 5틱은 AI만 진행
                bool aiBidOccurred = false;
                for (int i = 0; i < TickSeconds.Length; i++)
                {
                    double t = TickSeconds[i];
                    double prob = ProbBid(price, trueValue, t);
                    double u = _rng.NextDouble();

                    Console.WriteLine($"[틱 {i+1}/5, t={t:0.#}s] 현재가 {price:N0}원 | AI 입찰확률 {prob*100:0.000}% (rand={u:0.0000})");

                    if (u < prob)
                    {
                        int aiBid = NextBid(price, trueValue);
                        aiBidOccurred = true;

                        if (playersBidThisRound.HasValue)
                        {
                            // 규칙: AI가 '플레이어가 부른 금액 이상(≥)'으로 입찰하면 AI 승 → 다음 라운드
                            if (aiBid >= playersBidThisRound.Value)
                            {
                                price = aiBid;
                                lastBidder = "AI";
                                Console.WriteLine($"→ AI가 {price:N0}원(플레이어 입찰 {playersBidThisRound.Value:N0} 이상)에 입찰! AI 승 → 다음 라운드");
                                break; // 라운드 종료, 다음 라운드로
                            }
                            else
                            {
                                // 이 경우는 거의 없지만(호가 규칙상 일반적으로 ≥가 됨), 안전하게 처리
                                price = aiBid;
                                lastBidder = "AI";
                                Console.WriteLine($"→ AI가 {price:N0}원에 입찰(플레이어 입찰에 미달). 계속 진행");
                                // 계속 5틱 내에서 다음 틱 시도
                            }
                        }
                        else
                        {
                            // 플레이어가 이번 라운드에 입찰 안 했으면, AI가 한 번이라도 부르면 다음 라운드
                            price = aiBid;
                            lastBidder = "AI";
                            Console.WriteLine($"→ AI가 {price:N0}원에 입찰! (플레이어 패스 라운드) → 다음 라운드");
                            break; // 라운드 종료, 다음 라운드
                        }
                    }
                    else
                    {
                        Console.WriteLine("→ AI 패스");
                    }

                    // (참고) 플레이어 5틱은 묻지 않음 — 요구사항 반영
                }

                // 라운드 종료 처리
                if (!aiBidOccurred)
                {
                    // 5틱 동안 AI가 한 번도 못 불렀다면 경매 종료
                    Console.WriteLine($"\n=== 경매 종료 ===");
                    Console.WriteLine($"낙찰가: {price:N0}원 / 낙찰자: {lastBidder}");
                    Console.WriteLine(price > trueValue ? "※ 시장가 초과(오버페이)!" : "시장가 이하 낙찰");
                    return;
                }

                // 다음 라운드로
                round++;
            }

            Console.WriteLine("\n최대 라운드 도달로 종료");
        }

        // --- 확률식 (v 이하: (1-p/v)^A, v 이상: Tau * exp(-Beta*(p/v-1)) ) ---
        private double ProbBid(int p, int v, double t)
        {
            if (v <= 0) return 0;
            double tt = Clamp(t / Math.Max(_p.T, 1e-6), 0, 1);
            double timeTerm = _p.Lambda + Math.Pow(tt, _p.Gamma);
            double x = (double)p / v;

            double priceTerm = x < 1.0
                ? Math.Pow(Math.Max(0.0, 1.0 - x), _p.A)
                : _p.Tau * Math.Exp(-_p.Beta * (x - 1.0)); // v 이상 꼬리 확률(오버페이 허용)

            return Math.Min(1.0, Math.Max(0.0, priceTerm * timeTerm));
        }

        // --- 다음 호가 (오버페이 허용)
        private int NextBid(int p, int v)
        {
            int step;
            if (p < v)
            {
                int gap = v - p;
                step = Math.Max(_p.MinStep, (int)Math.Round(gap * _p.Eta));
            }
            else
            {
                step = Math.Max(_p.MinStep, (int)Math.Round(v * _p.EtaAbove));
            }
            long cand = (long)p + step;
            return (int)Math.Min(int.MaxValue, cand);
        }

        private static double Clamp(double x, double lo, double hi)
            => x < lo ? lo : (x > hi ? hi : x);
    }
}
