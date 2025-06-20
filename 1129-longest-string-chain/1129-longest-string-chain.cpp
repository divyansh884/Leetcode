class Solution {
public:
static bool compare(string &s1,string &s2)
{
    return s1.size() < s2.size();
}
bool comp(string &word2, string &word1){
    int i=word2.size()-1,j=word1.size()-1;
    if(i!= j+1) return false;
    while(i>=0 && j>=0){
        if(word2[i]==word1[j]){
            i--;
            j--;
        }
        else{
            i--;
        }
    }
    if(j<0)
    return true;
    return false;
}
    int longestStrChain(vector<string>& words) {
         int n= words.size();
        vector<int> dp(n,1);
        int maxi=0;
        sort(words.begin(),words.end(),compare);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(comp(words[i],words[j]) && dp[j]+1>dp[i] ){
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};