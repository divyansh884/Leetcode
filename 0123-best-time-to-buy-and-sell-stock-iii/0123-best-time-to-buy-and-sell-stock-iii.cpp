class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = 0; i < 2; i++ ) {
            for (int j = 0; j < 3; j++) {
                dp[prices.size()][i][j] = 0;
            }
        }
        for (int i = 0; i <= prices.size(); i++ ) {
            for (int j = 0; j < 2; j++) {
                dp[i][j][2] = 0;
            }
        }
        for (int ind = prices.size() - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int count = 1; count < 3; count++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[ind] +dp[ind+1][0][count],dp[ind+1][1][count]);
                    } else {
                        profit = max(prices[ind] + dp[ind+1][1][count-1],dp[ind+1][0][count]);
                    }
                    dp[ind][buy][count]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};