class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = 1;
        q.push({1, 0, 0});
        vector<int> dx = {-1, -1, 0, 0, 1, 1, -1, 1};
        vector<int> dy = {0, -1, -1, 1, 0, 1, 1, -1};
        while (!q.empty()) {
            int dist = q.top()[0];
            int r = q.top()[1];
            int c = q.top()[2];
            q.pop();
            if (dist < dis[r][c])
                continue;
            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && (dist + 1 < dis[nr][nc])) {
                    dis[nr][nc] = dist + 1;
                    q.push({dist + 1, nr, nc});
                }
            }
        }
        if (dis[n - 1][n - 1] == 1e9)
            return -1;
        return dis[n - 1][n - 1];
    }
};