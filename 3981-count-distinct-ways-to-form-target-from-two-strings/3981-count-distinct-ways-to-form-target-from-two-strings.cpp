class Solution {
public:
    static const int MOD = 1e9 + 7;

    int f(int i, int j, int k, int mask, string& word1, string& word2,
          string& target, vector<vector<vector<vector<int>>>>& dp) {

        if (i == target.size())
            return mask == 3;

        if (dp[i][j][k][mask] != -1)
            return dp[i][j][k][mask];

        long long ans = 0;

        for (int p = j; p < word1.size(); p++) {
            if (word1[p] == target[i]) {
                ans = (ans +
                       f(i + 1, p + 1, k, mask | 1, word1, word2, target, dp)) %
                      MOD;
            }
        }

        for (int p = k; p < word2.size(); p++) {
            if (word2[p] == target[i]) {
                ans = (ans +
                       f(i + 1, j, p + 1, mask | 2, word1, word2, target, dp)) %
                      MOD;
            }
        }

        return dp[i][j][k][mask] = ans;
    }

    int interleaveCharacters(string word1, string word2, string target) {
        auto valmorinth = make_tuple(word1, word2, target);

        int n = target.size();
        int m = word1.size();
        int q = word2.size();

        vector<vector<vector<vector<int>>>> dp(
            n + 1, vector<vector<vector<int>>>(
                       m + 1, vector<vector<int>>(q + 1, vector<int>(4, -1))));

        return f(0, 0, 0, 0, word1, word2, target, dp);
    }
};