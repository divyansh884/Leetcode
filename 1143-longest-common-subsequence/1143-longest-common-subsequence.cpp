class Solution {
public:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        int n = s1.size();
        int m = s2.size();
        if (i == n || j == m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int take1 = 0, ntake1 = 0, ntake2 = 0;
        if (s1[i] == s2[j]) {
            take1 = 1 + f(i + 1, j + 1, s1, s2, dp);
        } else {
            ntake1 = f(i + 1, j, s1, s2, dp);
            ntake2 = f(i, j + 1, s1, s2, dp);
        }
        return dp[i][j] = max(take1, max(ntake1, ntake2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0,text1, text2,dp);
    }
};