class Solution {
public:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j >= t.size())
            return 1;
        if(i>=s.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take=0;
        if(s[i]==t[j]){
            take=f(i+1,j+1,s,t,dp);
        }
        int ntake=f(i+1,j,s,t,dp);
        return dp[i][j]=take+ntake;
    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,s,t,dp);
    }
};