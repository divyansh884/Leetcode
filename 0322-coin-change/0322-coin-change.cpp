class Solution {
public:
int f(int i,int left,vector<int> &coins, vector<vector<int>> &dp){
    if(left==0)
    return 0;
    if(i>=coins.size())
    return 1e9;
    if(dp[i][left]!=-1) return dp[i][left];
    int take=1e9;
    if(left-coins[i]>=0)
    take=1+f(i,left-coins[i],coins,dp);
    int ntake=f(i+1,left,coins,dp);
    return dp[i][left]=min(take,ntake);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int re=f(0,amount,coins,dp);
        if(re==1e9)
        return -1;
        return re;
    }
};