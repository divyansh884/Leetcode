class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>>& matrix,
          vector<vector<int>>& dp) {

        if (i == n - 1)
            return matrix[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int ans = INT_MAX;

        if (j - 1 >= 0)
            ans = min(ans, matrix[i][j] + f(i + 1, j - 1, n, matrix, dp));

        ans = min(ans, matrix[i][j] + f(i + 1, j, n, matrix, dp));

        if (j + 1 < n)
            ans = min(ans, matrix[i][j] + f(i + 1, j + 1, n, matrix, dp));

        return dp[i][j] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, f(0, j, n, matrix, dp));
        }
        return ans;
    }
};
