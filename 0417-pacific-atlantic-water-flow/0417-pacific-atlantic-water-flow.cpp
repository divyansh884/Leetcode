class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& visited,
             vector<vector<int>>& heights) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        queue<pair<int, int>> q1, q2;
        for (int i = 0; i < n; i++) {
            pacific[i][0] = 1;
            q1.push({i, 0});
        }
        for (int j = 0; j < m; j++) {
            pacific[0][j] = 1;
            q1.push({0, j});
        }
        for (int i = 0; i < n; i++) {
            atlantic[i][m - 1] = 1;
            q2.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            atlantic[n - 1][j] = 1;
            q2.push({n - 1, j});
        }
        bfs(q1, pacific, heights);
        bfs(q2, atlantic, heights);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
