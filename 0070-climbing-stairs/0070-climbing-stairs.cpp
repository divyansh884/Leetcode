class Solution {
public:
int f(int strt,int n,vector<int> &dp){
if(strt>=n){
    if(strt==n)
    return 1;
    return 0;
}
if(dp[strt]!=-1) return dp[strt];
int op1=f(strt+1,n,dp);
int op2=f(strt+2,n,dp);
return dp[strt]=op1+op2;
}
    int climbStairs(int n) {
       int strt=0;
       vector<int> dp(n+1,-1);
       return f(strt,n,dp); 
    }
};