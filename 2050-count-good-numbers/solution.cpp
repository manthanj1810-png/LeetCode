class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long fastPow(long long x, long long n) {
        if (n == 0) return 1;

        long long half = fastPow(x, n / 2);
        half = (half * half) % MOD;

        if (n % 2 == 0)
            return half;
        else
            return (x * half) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos  = n / 2;

        long long ans = (fastPow(5, evenPos) * fastPow(4, oddPos)) % MOD;
        return (int)ans;
    }
};

