class Solution {
public:
int f(int i,int j,string &s, string &t,vector<vector<int>> &dp){
    if(j<0)
    return 1;
    if(i<0)
    return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int take=0;
    if(s[i]==t[j])
    take=f(i-1,j-1,s,t,dp);
    int ntake=f(i-1,j,s,t,dp);
    return dp[i][j]= ntake+take;
}
    int numDistinct(string s, string t) {
        vector<vector<int>>  dp(s.size(),vector<int>(t.size(),-1));
        return f(s.size()-1,t.size()-1,s,t,dp);
    }
};