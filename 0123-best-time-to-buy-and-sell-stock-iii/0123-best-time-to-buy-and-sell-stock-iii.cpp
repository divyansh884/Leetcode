class Solution {
public:
    int f(int i, int buy, int left, vector<int>& p,
          vector<vector<vector<int>>>& dp) {
        int n = p.size();
        if (left <= 0 || i == n)
            return 0;
        if (dp[i][buy][left] != -1)
            return dp[i][buy][left];
        int take = 0, ntake = 0, take1 = 0, ntake1 = 0;
        if (buy) {
            take = -p[i] + f(i + 1, 0, left, p, dp);
            ntake = f(i + 1, 1, left, p, dp);
            return dp[i][buy][left] = max(take, ntake);
        } else {
            take1 = +p[i] + f(i + 1, 1, left - 1, p, dp);
            ntake1 = f(i + 1, 0, left, p, dp);
            return dp[i][buy][left] = max(take1, ntake1);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};