class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] <= buy) {
                buy = prices[i];
            }
            else {
                profit+=prices[i]-buy;
                buy=prices[i];
            }
        }
        return profit;
    }
};