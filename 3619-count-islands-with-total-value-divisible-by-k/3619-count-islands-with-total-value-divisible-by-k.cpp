class Solution {
private:
    long long dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] <= 0) {
            return 0;
        }
        long long current_val = grid[r][c];
        grid[r][c] = 0;
        current_val += dfs(grid, r + 1, c, m, n);
        current_val += dfs(grid, r - 1, c, m, n);
        current_val += dfs(grid, r, c + 1, m, n);
        current_val += dfs(grid, r, c - 1, m, n);
        return current_val;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int divisible_island_count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long island_sum = dfs(grid, i, j, m, n);
                    if (island_sum % k == 0) {
                        divisible_island_count++;
                    }
                }
            }
        }
        return divisible_island_count;
    }
};