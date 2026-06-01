class Solution {
public:
    void f(int i, int j, vector<vector<char>>& b, vector<vector<int>>& vis,
           int& m, int& n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && b[nr][nc] == 'O' &&
                    !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && board[0][i] == 'O') {
                vis[0][i] = 1;
                f(0, i, board, vis, m, n);
            }
            if (!vis[m - 1][i] && board[m - 1][i] == 'O') {
                vis[m - 1][i] = 1;
                f(m - 1, i, board, vis, m, n);
            }
        }
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                vis[i][0] = 1;
                f(i, 0, board, vis, m, n);
            }
            if (!vis[i][n - 1] && board[i][n - 1] == 'O') {
                vis[i][n - 1] = 1;
                f(i, n - 1, board, vis, m, n);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(!vis[i][j])
                board[i][j]='X';
            }
        }
    }
};