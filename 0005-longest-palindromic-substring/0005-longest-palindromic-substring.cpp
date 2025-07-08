class Solution {
public:
void f(int i,int j, string &word1,string&word2,int n,string keep,vector<string> &ans,vector<vector<int>> &dp){
    if(i>=n|| j>=n){
        if(!keep.empty())
        ans.push_back(keep);
    return;
    }
    if(word1[i]==word2[j]){
        f(i+1,j+1,word1,word2,n,keep+word1[i],ans,dp);
    }
    else{
        if(!keep.empty())
        ans.push_back(keep);
        f(i+1,j,word1,word2,n,"",ans,dp);
        f(i,j+1,word1,word2,n,"",ans,dp);
    }
}
    string longestPalindrome(string s) {
        vector<string> ans;
        int n=s.size();
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        f(0,0,s,s1,n,"",ans,dp);
         sort(ans.begin(), ans.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    return ans.back();
    }
};