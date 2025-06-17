class Solution {
public:
int f(int index1,int index2,string &text1, string &text2,vector<vector<int>> &dp){
    if(index1<0 || index2<0)
    return 0;
    int take=0,ntake=0;
    if(dp[index1][index2]!=-1) return dp[index1][index2];
    if(text1[index1]==text2[index2]){
        take+=1+f(index1-1,index2-1,text1,text2,dp);
    }
    if(text1[index1]!=text2[index2]){
        ntake+=max(f(index1-1,index2,text1,text2,dp),f(index1,index2-1,text1,text2,dp));
    }
    return dp[index1][index2]=max(take,ntake);
}
    int minInsertions(string s) {
        int index1=s.size()-1;
        int index2=s.size()-1;
        vector<vector<int>> dp(index1+1,vector<int>(index2+1,-1));
        string s1=s;
        reverse(s1.begin(),s1.end());
        int re=f(index1,index2,s,s1,dp);
        return s.size()-re;
    }
};