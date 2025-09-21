class Solution {
public:
int f(int n,vector<int> &dp){
    if(n==0)
    return 1;
    if(dp[n]!=-1)return dp[n];
    int take2=0;
    if(n>=2)
    take2+=f(n-2,dp);
    int take1=f(n-1,dp);
    return dp[n]=take2+take1;
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};