class Solution {
public:
    int f(int i, int j, string& w1, string& w2, vector<vector<int>>& dp) {
        int n = w2.size();
        int m = w1.size();
        if (j == n)
            return m - i;
        if (i == m)
            return n - j;
        if (dp[i][j] != -1)
            return dp[i][j];
        int take = 1e9, ntake1 = 1e9, ntake2 = 1e9, ntake3 = 1e9;
        if (w1[i] == w2[j]) {
            take = f(i + 1, j + 1, w1, w2, dp);
        } else {
            ntake1 = 1 + f(i + 1, j + 1, w1, w2, dp);
            ntake2 = 1 + f(i + 1, j, w1, w2, dp);
            ntake3 = 1 + f(i, j + 1, w1, w2, dp);
        }
        return dp[i][j] = min(take, min(ntake1, min(ntake2, ntake3)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, word1, word2, dp);
    }
};