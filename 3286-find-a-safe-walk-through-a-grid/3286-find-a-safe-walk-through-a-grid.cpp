class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> best(m, vector<int>(n, -1));
        int start = health - grid[0][0];
        if (start <= 0)
            return false;
        q.push({start, 0, 0});
        best[0][0] = start;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int he = cur[0];
            int r = cur[1];
            int c = cur[2];
            if (r == m - 1 && c == n - 1)
                return true;
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nh = he - grid[nr][nc];
                    if (nh > 0 && nh > best[nr][nc]) {
                        best[nr][nc] = nh;
                        q.push({nh, nr, nc});
                    }
                }
            }
        }
        return false;
    }
};