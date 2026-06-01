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
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && b[nr][nc] == '1' &&
                    !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == '1'){
                    ans++;
                    vis[i][j]=1;
                    f(i,j,board,vis,m,n);
                }
            }
        }
        return ans;
    }
};