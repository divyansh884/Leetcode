class Solution {
public:
int f(int ind,vector<int> &prices,bool buy,int count,int n,vector<vector<vector<int>>> &dp){
    if(count>=2){
        return 0;
    }
    if(ind>=n)
    return 0;
    int profit=0;
    if(dp[ind][buy][count]!=-1) return dp[ind][buy][count];
    if(buy){
        profit= max(-prices[ind]+f(ind+1,prices,0,count,n,dp),f(ind+1,prices,1,count,n,dp));
    }
    else{
        profit= max(prices[ind]+f(ind+1,prices,1,count+1,n,dp),f(ind+1,prices,0,count,n,dp));
    }
    return dp[ind][buy][count]=profit;
}
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0,prices,1,0,prices.size(),dp);
    }
};