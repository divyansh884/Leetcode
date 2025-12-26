class Solution {
public:
int f(int i,int left,vector<int> &coins, vector<vector<int>> &dp){
    if(left==0)
    return 1;
    if(i>=coins.size())
    return 0;
    if(dp[i][left]!=-1) return dp[i][left];
    int take=0;
    if(left-coins[i]>=0)
    take=f(i,left-coins[i],coins,dp);
    int ntake=f(i+1,left,coins,dp);
    return dp[i][left]=take+ntake;
}
    int change(int amount,vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int re=f(0,amount,coins,dp);
        return re;
    }
};