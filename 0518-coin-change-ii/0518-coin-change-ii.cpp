class Solution {
public:
int f(int index,vector<int> & coins,int amount,int n,vector<vector<int>> &dp){
    if(index==0){
        if(amount%coins[0]==0){
            return 1;
        }
        return 0;
    }
    if(dp[index][amount]!=-1) return dp[index][amount];
    int take=0,ntake=0;
    ntake+=f(index-1,coins,amount,n,dp);
    if(amount>=coins[index]) take+=f(index,coins,amount-coins[index],n,dp);
    return dp[index][amount]=take+ntake;
}
    int change(int amount, vector<int>& coins) {
      int n=coins.size(),index=n-1,cnt=0;
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res=f(index,coins,amount,n,dp);
        return res;
    }
};