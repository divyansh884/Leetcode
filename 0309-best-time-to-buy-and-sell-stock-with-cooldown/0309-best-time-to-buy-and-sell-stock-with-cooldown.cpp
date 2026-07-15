class Solution {
public:
    int f(int day, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();

        if (day >= n)
            return 0;

        if (dp[day][buy] != -1)
            return dp[day][buy];

        if (buy) {

            int take = -prices[day] + f(day + 1, 0, prices, dp);
            int notTake = f(day + 1, 1, prices, dp);

            return dp[day][buy] = max(take, notTake);
        } else {

            int sell = prices[day] + f(day + 2, 1, prices, dp);
            int hold = f(day + 1, 0, prices, dp);

            return dp[day][buy] = max(sell, hold);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, dp);
    }
};