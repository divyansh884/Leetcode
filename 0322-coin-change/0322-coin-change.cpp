class Solution {
public:
int f(int index,vector<int> & coins,int amount,int n,vector<vector<int>> &dp){
    if(index==0){
        if(amount%coins[0]==0){
            int cc= amount/coins[0];
            return cc;
        }
        return 1e9;
    }
    if(dp[index][amount]!=-1) return dp[index][amount];
    int take=1e9;
    int ntake=f(index-1,coins,amount,n,dp);
    if(amount>=coins[index]) take=1+f(index,coins,amount-coins[index],n,dp);
    return dp[index][amount]=min(take,ntake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(),index=n-1,cnt=0;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int res=f(index,coins,amount,n,dp);
        if(res!=1e9)
        return res; 
        return -1;
    }
};