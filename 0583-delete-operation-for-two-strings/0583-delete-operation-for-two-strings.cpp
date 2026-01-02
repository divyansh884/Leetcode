class Solution {
public:
    int f(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int match = 0, nmatch1 = 0, nmatch2 = 0;
        if (text1[i] == text2[j])
            match = 1 + f(i - 1, j - 1, text1, text2, dp);
        else {
            nmatch1 = f(i - 1, j, text1, text2, dp);
            nmatch2 = f(i, j - 1, text1, text2, dp);
        }
        return dp[i][j] = max(match, max(nmatch1, nmatch2));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        int it= f(word1.size()-1,word2.size()-1,word1,word2,dp);
        return word1.size()+word2.size()-2*it;
    }
};