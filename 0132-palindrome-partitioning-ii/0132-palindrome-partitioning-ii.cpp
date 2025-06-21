class Solution {
public:
bool poss(string &s){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-i-1])
        return false;
    }
    return true;
}

int f(int i,string &s, int n,vector<int> &dp){
    if(i>=n)
    return 0;
    string temp="";
    if(dp[i]!=-1) return dp[i];
    int mini=1e9;
    for(int j=i;j<n;j++){
        temp+=s[j];
        if(poss(temp)){
            int sum=1+ f(j+1,s,n,dp);
            mini=min(mini,sum);
        }
    }
   return dp[i]=mini;
}
    int minCut(string s) {
        int n= s.size();
        vector<int> dp(n+1,-1);
        return f(0,s,n,dp)-1;
    }
};