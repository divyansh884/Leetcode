class Solution {
public:
    bool f(int i, int j, string& s, vector<string>& wordDict, int &n,
           vector<vector<int>> &dp) {
        if (j == n) {
            if (i == j)
                return true;
            return false;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        bool take = false, ntake = false;
        string req = s.substr(i, j - i + 1);
        if (find(wordDict.begin(), wordDict.end(), req) != wordDict.end()) {
            take = f(j + 1, j + 1, s, wordDict, n,dp);
        }
        ntake = f(i, j + 1, s, wordDict, n,dp);
        return dp[i][j] = take || ntake;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(0, 0, s, wordDict, n, dp);
    }
};