class Solution {
public:
    int f(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0){
            int add=0;
            while(i>=0){
                add+=int(text1[i]);
                i--;
            }
            while(j>=0){
                add+=int(text2[j]);
                j--;
            }
            return add;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int match = 1e9, nmatch1 = 1e9, nmatch2 = 1e9;
        if (text1[i] == text2[j])
            match = min(f(i - 1, j - 1, text1, text2, dp),
                        2*int(text1[i]) + f(i - 1, j - 1, text1, text2, dp));
        else {
            nmatch1 = int(text1[i])+f(i - 1, j, text1, text2, dp);
            nmatch2 = int(text2[j])+f(i, j - 1, text1, text2, dp);
        }
        return dp[i][j] = min(match, min(nmatch1, nmatch2));
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(), -1));
        return f(s1.size() - 1, s2.size() - 1, s1, s2, dp);
    }
};