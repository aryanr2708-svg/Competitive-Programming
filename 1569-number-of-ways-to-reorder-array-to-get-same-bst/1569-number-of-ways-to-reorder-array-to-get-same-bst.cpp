class Solution {
    int mod = 1e9+7;
    vector<vector<long long>> comb;
    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) {
            return 1;
        }
        vector<int> left;
        vector<int> right;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        long long leftWays = dfs(left) % mod;
        long long rightWays = dfs(right) % mod;
        long long ways = comb[nums.size() - 1][left.size()];
        ways = (ways * leftWays) % mod;
        ways = (ways * rightWays) % mod;
        return ways;
    }
public:
    int numOfWays(vector<int>& n) {
        int sz = n.size();
        comb = vector<vector<long long>>(sz + 1, vector<long long>(sz + 1, 0));
        for (int i = 0; i <= sz; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
            }
        }
        return (dfs(n) - 1 + mod) % mod;
    }
};