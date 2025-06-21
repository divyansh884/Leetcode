class Solution {
public:
 bool check(string &s, int i, int j) {
        while(i <= j && s[i] == s[j]) {
            i++;
            j--;
        }
        return i > j;
    }

int f(int i,string &s, int n,vector<int> &dp){
    if(i>=n)
    return 0;
    if(dp[i]!=-1) return dp[i];
    int mini=1e9;
    for(int j=i;j<n;j++){
        if(check(s,i,j)){
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