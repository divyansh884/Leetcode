class Solution {
public:
    int f(int day, int buy, vector<int>& prices, vector<vector<int>>& dp,
          int& fee) {
        int n = prices.size();

        if (day >= n)
            return 0;

        if (dp[day][buy] != -1)
            return dp[day][buy];

        if (buy) {

            int take = -prices[day] + f(day + 1, 0, prices, dp, fee);
            int notTake = f(day + 1, 1, prices, dp, fee);

            return dp[day][buy] = max(take, notTake);
        } else {

            int sell = prices[day] - fee + f(day + 1, 1, prices, dp, fee);
            int hold = f(day + 1, 0, prices, dp, fee);

            return dp[day][buy] = max(sell, hold);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, dp, fee);
    }
};