class Solution {
public:
    int numberOfSets(int n, int k) {
        long long N = n + k - 1;
        long long R = 2 * k;
        if (R > N) return 0;
        long long mod = 1e9 + 7;
        long long num = 1;
        long long den = 1;
        if (R > N - R) {
            R = N - R;
        }
        for (long long i = 1; i <= R; ++i) {
            num = (num * (N - i + 1)) % mod;
            den = (den * i) % mod;
        }
        long long exp = mod - 2;
        long long inv = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                inv = (inv * den) % mod;
            }
            den = (den * den) % mod;
            exp /= 2;
        }
        return (num * inv) % mod;
    }
};