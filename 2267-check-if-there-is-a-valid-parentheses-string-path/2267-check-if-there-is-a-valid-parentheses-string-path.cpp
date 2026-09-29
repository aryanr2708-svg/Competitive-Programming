#include <vector>

class Solution {
public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        int max_bal = (m + n) / 2;
        std::vector<std::vector<std::vector<bool>>> dp(m, std::vector<std::vector<bool>>(n, std::vector<bool>(max_bal + 1, false)));
        dp[0][0][1] = true;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int delta = (grid[i][j] == '(') ? 1 : -1;
                for (int bal = 0; bal <= max_bal; ++bal) {
                    if (dp[i][j][bal]) {
                        if (i + 1 < m) {
                            int next_bal = bal + ((grid[i + 1][j] == '(') ? 1 : -1);
                            if (next_bal >= 0 && next_bal <= max_bal) {
                                dp[i + 1][j][next_bal] = true;
                            }
                        }
                        if (j + 1 < n) {
                            int next_bal = bal + ((grid[i][j + 1] == '(') ? 1 : -1);
                            if (next_bal >= 0 && next_bal <= max_bal) {
                                dp[i][j + 1][next_bal] = true;
                            }
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};
