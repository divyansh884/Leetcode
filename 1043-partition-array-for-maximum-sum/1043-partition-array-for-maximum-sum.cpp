class Solution {
public:
    int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp, int k) {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (j - i + 1 <= k) {
            int maxi = INT_MIN;
            for (int x = i; x <= j; x++)
                maxi = max(maxi, arr[x]);

            return dp[i][j] = (j - i + 1) * maxi;
        }
        int ans = 0;
        for (int m = i; m < j; m++) {
            ans = max(ans, f(i, m, arr, dp, k) + f(m + 1, j, arr, dp, k));
        }
        return dp[i][j] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n - 1, arr, dp, k);
    }
};