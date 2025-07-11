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

    int minDistance(string text1, string text2) {
         int index1=text1.size()-1;
        int index2=text2.size()-1;
        vector<vector<int>> dp(index1+1,vector<int>(index2+1,-1));
        int re= f(index1,index2,text1,text2,dp);
        int ans=text1.size()-re+text2.size()-re;
        return ans;
    }
};