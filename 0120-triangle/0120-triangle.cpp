class Solution {
public:
    int f(int i, int j, int m,
          vector<vector<int>>& grid,
          vector<vector<int>>& dp) {

        if (i == m - 1)
            return grid[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int down = grid[i][j] + f(i + 1, j, m, grid, dp);
        int diag = grid[i][j] + f(i + 1, j + 1, m, grid, dp);

        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
        return f(0, 0, m, triangle, dp);
    }
};
