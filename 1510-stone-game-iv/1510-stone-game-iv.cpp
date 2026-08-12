class Solution {
public:
    bool f(int left, int check, vector<vector<int>>& dp) {
        if (left <= 0)
            return false;

        if (dp[left][check] != -1)
            return dp[left][check];

        bool checke = false;

        for (int i = 1; i * i <= left; i++) {
            int sub = i * i;

            bool temp = f(left - sub, !check, dp);

            if (!temp) {
                checke = true;
                break;
            }
        }

        return dp[left][check] = checke;
    }

    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(n, 0, dp);
    }
};