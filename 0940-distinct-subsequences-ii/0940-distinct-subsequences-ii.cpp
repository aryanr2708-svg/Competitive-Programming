class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<long long> last(26, 0);
        for (char c : s) {
            int charIdx = c - 'a';
            long long currentTotal = 0;
            for (int i = 0; i < 26; ++i) {
                currentTotal = (currentTotal + last[i]) % MOD;
            }
            last[charIdx] = (currentTotal + 1) % MOD;
        }
        long long finalAns = 0;
        for (int i = 0; i < 26; ++i) {
            finalAns = (finalAns + last[i]) % MOD;
        }
        return finalAns;
    }
};