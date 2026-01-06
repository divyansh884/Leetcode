class Solution {
public:
 int f(int i, int buy,vector<int> &prices,vector<vector<int>> &dp){
    if(i>=prices.size())
    return 0;
    int take=0;
    int pf1=0,pf2=0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy){
        pf1=max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
    }
    else{
        pf2=max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
    }
    return dp[i][buy]=max(pf1,pf2);
 }
    int maxProfit(std::vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,dp);
        
    }
};