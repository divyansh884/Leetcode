class Solution {
public:
    int f(int i, int check, vector<int>& pre, vector<vector<int>>& dp) {
        int n = pre.size();

        if (i == n - 2) {
            if (check)
                return pre[n - 1];
            return -pre[n - 1];
        }
        if (dp[i][check] != INT_MIN)
            return dp[i][check];

        int take, ntake;

        if (check == 1) {
            take = pre[i + 1] + f(i + 1, 0, pre, dp);
            ntake = f(i + 1, 1, pre, dp);
            return dp[i][check] = max(take, ntake);
        } else {
            take = -pre[i + 1] + f(i + 1, 1, pre, dp);
            ntake = f(i + 1, 0, pre, dp);
            return dp[i][check] = min(take, ntake);
        }
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> pre(n);
        pre[0] = stones[0];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));

        return f(0, 1, pre, dp);
    }
};