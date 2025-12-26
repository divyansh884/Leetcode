class Solution {
public:
int f(int i,int j,string text1,string text2,vector<vector<int>> &dp){
    if(i<0 || j<0)
    return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int match=0,nmatch1=0,nmatch2=0;
    if(text1[i]==text2[j])
    match=1+ f(i-1,j-1,text1,text2,dp);
    else{
    nmatch1=f(i-1,j,text1,text2,dp);
    nmatch2=f(i,j-1,text1,text2,dp);
    }
    return dp[i][j]=max(match,max(nmatch1,nmatch2));
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return f(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};