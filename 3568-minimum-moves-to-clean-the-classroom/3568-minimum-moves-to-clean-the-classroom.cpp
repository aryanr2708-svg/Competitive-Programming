class Solution {
    bool visited[20][20][1 << 10][51];
    int litter_idx[20][20];
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        if (n == 0) return -1;
        int m = classroom[0].size();
        int start_r = -1, start_c = -1;
        int k = 0;
        memset(litter_idx, -1, sizeof(litter_idx));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_idx[i][j] = k++;
                }
            }
        }
        if (k == 0) return 0;
        queue<tuple<int, int, int, int, int>> q;
        q.push({start_r, start_c, 0, energy, 0});
        visited[start_r][start_c][0][energy] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int target_mask = (1 << k) - 1;
        while (!q.empty()) {
            auto [r, c, mask, e, moves] = q.front();
            q.pop();
            if (mask == target_mask) return moves;
            if (e == 0 && classroom[r][c] != 'R') continue;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (classroom[nr][nc] == 'X') continue;
                int ne = e - 1;
                if (ne < 0) continue;
                int nmask = mask;
                int l_idx = litter_idx[nr][nc];
                if (l_idx != -1) {
                    nmask |= (1 << l_idx);
                }
                int final_e = (classroom[nr][nc] == 'R') ? energy : ne;
                if (nmask == target_mask) return moves + 1;
                if (!visited[nr][nc][nmask][final_e]) {
                    visited[nr][nc][nmask][final_e] = true;
                    q.push({nr, nc, nmask, final_e, moves + 1});
                }
            }
        }
        return -1;
    }
};
