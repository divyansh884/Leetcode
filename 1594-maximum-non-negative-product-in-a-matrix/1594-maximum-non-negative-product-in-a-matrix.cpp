class Solution {
public:
    int MOD = 1e9 + 7;

    pair<long long, long long> f(int i, int j, vector<vector<int>>& grid,
                                int& m, int& n,
                                vector<vector<pair<long long,long long>>>& dp) {

        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        if (dp[i][j].first != LLONG_MIN)
            return dp[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        if (i + 1 < m) {
            auto down = f(i + 1, j, grid, m, n, dp);
            long long a = grid[i][j] * down.first;
            long long b = grid[i][j] * down.second;
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        if (j + 1 < n) {
            auto right = f(i, j + 1, grid, m, n, dp);
            long long a = grid[i][j] * right.first;
            long long b = grid[i][j] * right.second;
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(
            m, vector<pair<long long,long long>>(n, {LLONG_MIN, LLONG_MIN})
        );

        auto res = f(0, 0, grid, m, n, dp);

        if (res.first < 0) return -1;
        return res.first % MOD;
    }
};