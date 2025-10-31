using System;
using System.Globalization;

namespace AuctionSim
{
    class Program
    {
        static void Main()
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Console.WriteLine("=== 경매 시뮬레이터 ===");
            int start = ReadInt("시작 가격(원): ");
            int trueV = ReadInt("진짜 가격/시장가(원): ");
            double aggr = ReadDouble("호전성(0~10): ", 0, 10);

            var prm = Params.FromAggressiveness(aggr);
            var sim = new Simulator(prm, seed: null);

            var result = sim.Run(start, trueV);

            Console.WriteLine("\n--- 결과 ---");
            Console.WriteLine($"최종가: {result.FinalPrice:N0}원");
            Console.WriteLine($"라운드 수: {result.Rounds}");
            Console.WriteLine($"오버페이 여부: {(result.FinalPrice > trueV ? "예(시장가 초과)" : "아니오")}");
            Console.WriteLine("\n(엔터를 누르면 상세 로그)");
            Console.ReadLine();

            Console.WriteLine("--- 상세 로그 (각 틱의 입찰확률/행동) ---");
            Console.WriteLine("Round | Tick | t(s) | Prob(bid) | rand u | Price after action");
            Console.WriteLine("----- | ---- | ---- | --------- | ------ | -------------------");
            foreach (var e in result.Events)
            {
                Console.WriteLine($"{e.Round,5} | {e.Tick,4} | {e.T,4:0.#} | {e.Prob*100,8:0.000}% | {e.U,6:0.0000} | {e.NewPrice,19:N0}");
            }
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

    // ------------------ 모델 파라미터 ------------------
    public class Params
    {
        // 가격 민감도/시간 가중/호가 크기
        public double A;         // (낮을수록 공격적)
        public double Lambda;    // 최저 참여도
        public double Gamma;     // 막판 가속(높을수록 막틱 의존)
        public double T = 10;    // 총 10초
        public int MinStep;      // 최소 호가단위
        public double Eta;       // v 이하에서 남은 차이 비율
        public double EtaAbove;  // v 이상에서 v 비율
        public double Tau;       // v 이상 꼬리 스케일(오버페이 허용)
        public double Beta;      // v 이상 감쇠(낮을수록 오버 꼬리 두꺼움)

        // 호전성(0~10) → 파라미터 보간
        public static Params FromAggressiveness(double g)
        {
            // 보수형(0) ~ 공격형(10) 프리셋
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

    // ------------------ 엔진 ------------------
    public class Simulator
    {
        private readonly Params _p;
        private readonly Random _rng;
        private static readonly double[] TickSeconds = { 2, 4, 6, 8, 10 };

        public Simulator(Params p, int? seed = null)
        {
            _p = p;
            _rng = seed.HasValue ? new Random(seed.Value) : new Random();
        }

        public SimResult Run(int startPrice, int trueValue, int maxRounds = 50)
        {
            int p = startPrice;
            int round = 1;
            var log = new System.Collections.Generic.List<SimEvent>();

            while (round <= maxRounds)
            {
                bool anyBid = false;
                for (int i = 0; i < TickSeconds.Length; i++)
                {
                    double t = TickSeconds[i];
                    double prob = ProbBid(p, trueValue, t);
                    double u = _rng.NextDouble();
                    bool willBid = u < prob;

                    int np = willBid ? NextBid(p, trueValue) : p;
                    log.Add(new SimEvent { Round = round, Tick = i + 1, T = t, Prob = prob, U = u, NewPrice = np });

                    if (willBid)
                    {
                        p = np;
                        anyBid = true;
                        break; // 입찰 시 즉시 타이머 리셋 → 다음 라운드
                    }
                }
                if (!anyBid) break; // 5틱 모두 실패 → 종료
                round++;
            }

            return new SimResult { FinalPrice = p, Rounds = round - 1, Events = log.ToArray() };
        }

        // 확률식
        private double ProbBid(int p, int v, double t)
        {
            if (v <= 0) return 0;
            double tt = Math.Clamp(t / Math.Max(_p.T, 1e-6), 0, 1);
            double timeTerm = _p.Lambda + Math.Pow(tt, _p.Gamma);
            double x = (double)p / v;

            double priceTerm;
            if (x < 1.0)
                priceTerm = Math.Pow(Math.Max(0.0, 1.0 - x), _p.A);
            else
                priceTerm = _p.Tau * Math.Exp(-_p.Beta * (x - 1.0)); // 꼬리 확률(오버페이 허용)

            return Math.Min(1.0, Math.Max(0.0, priceTerm * timeTerm));
        }

        // 호가 규칙
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
            // v 초과도 허용(오버페이 가능)
            long cand = (long)p + step;
            return (int)Math.Min(int.MaxValue, cand);
        }
    }

    // ------------------ DTO ------------------
    public class SimEvent
    {
        public int Round { get; set; }
        public int Tick { get; set; }
        public double T { get; set; }
        public double Prob { get; set; }
        public double U { get; set; }
        public int NewPrice { get; set; }
    }

    public class SimResult
    {
        public int FinalPrice { get; set; }
        public int Rounds { get; set; }
        public SimEvent[] Events { get; set; } = Array.Empty<SimEvent>();
    }
}
