class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if (j < 0) {
            if (i >= 0)
                return i + 1;
            return 0;
        }
        if (i < 0) {
            if (j >= 0)
                return j + 1;
            return 0;
        }
         if( dp[i][j]!=-1) return dp[i][j];
        int take = 1e9, ntake1 = 1e9, ntake2 = 1e9, ntake3 = 1e9;
        if (s1[i] == s2[j])
            take = f(i - 1, j - 1, s1, s2, dp);
        else {
            ntake1 = 1 + f(i, j - 1, s1, s2, dp);
            ntake2 = 1 + f(i - 1, j, s1, s2, dp);
            ntake3 = 1 + f(i - 1, j - 1, s1, s2, dp);
        }
        return dp[i][j]=min(take, min(ntake1, min(ntake2, ntake3)));
    }
    int minDistance(string word1, string word2) {
        if (word2.empty() || word1.empty())
            return max(word1.size(), word2.size());
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return f(word1.size() - 1, word2.size() - 1, word1, word2, dp);
    }
};