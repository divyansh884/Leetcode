class Solution {
public:
int f(int i,int buy,int cnt,vector<int> &prices,vector<vector<vector<int>>> &dp){
    if(i>=prices.size() || cnt>=2)
    return 0;
    int take=0,ntake=0;
     if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];
    if(buy){
        take=max(-prices[i]+f(i+1,0,cnt,prices,dp),f(i+1,1,cnt,prices,dp));
        
    }
    else{
        ntake=max(prices[i]+f(i+1,1,cnt+1,prices,dp),f(i+1,0,cnt,prices,dp));
    }
    return dp[i][buy][cnt]=max(ntake,take);
}
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,1,0,prices,dp);
    }
};