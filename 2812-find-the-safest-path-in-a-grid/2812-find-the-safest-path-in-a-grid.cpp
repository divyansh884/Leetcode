class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    dis[nr][nc] > dis[r][c] + 1) {
                    dis[nr][nc] = dis[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        priority_queue<vector<int>> pq;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        pq.push({dis[0][0], 0, 0});
        dist[0][0] = dis[0][0];
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int safe = cur[0];
            int r = cur[1];
            int c = cur[2];
            if (r == n - 1 && c == n - 1)
                return safe;
            if (safe < dist[r][c])
                continue;
            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newsafe = min(safe, dis[nr][nc]);
                    if (newsafe > dist[nr][nc]) {
                        dist[nr][nc] = newsafe;
                        pq.push({newsafe, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};