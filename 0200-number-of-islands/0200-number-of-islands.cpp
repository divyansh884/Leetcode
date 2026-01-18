class Solution {
public:
    void f(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({i, j});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = row + dx[i];
                int newy = col + dy[i];
                if (newx >= 0 && newy >= 0 && newx < grid.size() &&
                    newy < grid[0].size() && grid[newx][newy] == '1' &&
                    vis[newx][newy] == -1) {
                    vis[newx][newy] = 1;
                    q.push({newx, newy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), - 1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && vis[i][j] == -1) {
                    vis[i][j] = 1;
                    cnt++;
                    f(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};