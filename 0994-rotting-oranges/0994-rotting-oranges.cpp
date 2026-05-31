class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        while (!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int time = q.front()[2];
            ans = max(ans, q.front()[2]);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] &&
                    grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    grid[nr][nc]=2;
                    q.push({nr, nc, time + 1});
                }
            }
        }
         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};