class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> max_score(n, vector<int>(m, -1));
        vector<vector<int>> paths(n, vector<int>(m, 0));
        max_score[n - 1][m - 1] = 0;
        paths[n - 1][m - 1] = 1;
        int dr[] = {-1, 0, -1};
        int dc[] = {0, -1, -1};
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (paths[i][j] == 0) continue; 
                for (int k = 0; k < 3; ++k) {
                    int r = i + dr[k];
                    int c = j + dc[k];
                    if (r >= 0 && c >= 0 && board[r][c] != 'X') {
                        int val = 0;
                        if (board[r][c] >= '1' && board[r][c] <= '9') {
                            val = board[r][c] - '0';
                        }
                        int current_score = max_score[i][j] + val;
                        if (current_score > max_score[r][c]) {
                            max_score[r][c] = current_score;
                            paths[r][c] = paths[i][j];
                        } 
                        else if (current_score == max_score[r][c]) {
                            paths[r][c] = (paths[r][c] + paths[i][j]) % MOD;
                        }
                    }
                }
            }
        }
        if (paths[0][0] == 0) return {0, 0};
        
        return {max_score[0][0], paths[0][0]};
    }
};