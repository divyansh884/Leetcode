class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        q.push({0, 0, 0});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while (!q.empty()) {
            int dist = q.top()[0];
            int r = q.top()[1];
            int c = q.top()[2];
            q.pop();
            if (dist > dis[r][c])
                continue;
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int eff = abs(grid[r][c] - grid[nr][nc]);
                    int maxeff = max(eff, dist);
                    if (maxeff < dis[nr][nc]) {
                        dis[nr][nc] = maxeff;
                        q.push({maxeff, nr, nc});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};