class Solution {
public:
    const int mod = 1e9 + 7;

    int getMax(int i, int j, vector<string>& board, vector<vector<int>>& dpMax) {
        if (i < 0 || j < 0 || board[i][j] == 'X') 
            return -1e9;
        
        if (i == 0 && j == 0) 
            return 0;
            
        if (dpMax[i][j] != -1) 
            return dpMax[i][j];

        int val = 0;
        if (board[i][j] >= '1' && board[i][j] <= '9') {
            val = board[i][j] - '0';
        }

        int op1 = getMax(i - 1, j, board, dpMax);
        int op2 = getMax(i, j - 1, board, dpMax);
        int op3 = getMax(i - 1, j - 1, board, dpMax);

        int mx = max({op1, op2, op3});
        
        if (mx <= -1e9 / 2) 
            return dpMax[i][j] = -1e9;

        return dpMax[i][j] = mx + val;
    }

    int f(int i, int j, int sum, vector<string>& board, vector<vector<int>>& dp) {
        int n = board.size();
        int m = board[0].size();
        
        if (sum < 0) 
            return 0;
            
        if (i == 0 && j == 0) {
            if (sum == 0) 
                return 1;
            return 0;
        }
        
        int state = i * m + j;
        if (dp[state][sum] != -1) 
            return dp[state][sum];
            
        int dr[] = {-1, 0, -1};
        int dc[] = {0, -1, -1};
        int take = 0;
        
        for (int k = 0; k < 3; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && board[nr][nc] != 'X') {
                int val = 0;
                if (board[nr][nc] >= '1' && board[nr][nc] <= '9') {
                    val = board[nr][nc] - '0';
                }
                
                int temp = f(nr, nc, sum - val, board, dp) % mod;
                take = (take + temp) % mod;
            }
        }
        return dp[state][sum] = take;
    }
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> dpMax(n, vector<int>(m, -1));
        int sum = getMax(n - 1, m - 1, board, dpMax);
        
        if (sum < 0) 
            return {0, 0};
        
        vector<vector<int>> dp(n * m, vector<int>(sum + 1, -1));
        int no = f(n - 1, m - 1, sum, board, dp);
        
        return {sum, no};
    }
};