class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc,
                                  int color) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({sr,sc});
        int org=grid[sr][sc];
        grid[sr][sc]=color;
        while (!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] &&
                    grid[nr][nc] ==org ) {
                    vis[nr][nc] = 1;
                    grid[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return grid;
    }
};