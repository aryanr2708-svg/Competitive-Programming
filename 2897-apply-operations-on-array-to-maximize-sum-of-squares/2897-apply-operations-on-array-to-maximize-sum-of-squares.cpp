class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        vector<int> bitCount(30, 0);
        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        long long totalSumOfSquares = 0;
        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;
            for (int i = 29; i >= 0; --i) {
                if (bitCount[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCount[i]--;
                }
            }
            totalSumOfSquares = (totalSumOfSquares + (currentNum * currentNum) % MOD) % MOD;
        }
        return totalSumOfSquares;
    }
};
