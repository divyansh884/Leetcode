class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size(), n = og[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        bool check = true;
        for (int i = 0; i < n; i++) {
            if (og[0][i] == 0 && check)
                dp[0][i] = 1;
            else {
                dp[0][i] = 0;
                check = false;
            }
        }
        check = true;
        for (int i = 0; i < m; i++) {
            if (og[i][0] == 0 && check)
                dp[i][0] = 1;
            else {
                dp[i][0] = 0;
                check = false;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (og[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        if(dp[m - 1][n - 1]!=-1)
        return dp[m-1][n-1];
        return 0;
    }
};