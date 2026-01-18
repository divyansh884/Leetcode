class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        q.push({-1, -1});
        int cnt = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        bool check = false;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row == -1 && col == -1) {
                if (check)
                    cnt++;
                if (!q.empty())
                    q.push({-1,- 1});
                check = false;
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int newx = row + dx[i];
                int newy = col + dy[i];
                if (newx >= 0 && newy >= 0 && newx < m && newy < n &&
                    grid[newx][newy] == 1) {
                    check = true;
                    grid[newx][newy] = 2;
                    q.push({newx, newy});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return cnt;
    }
};