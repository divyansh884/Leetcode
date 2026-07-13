class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (auto it : arr)
            sum += it;
        if (sum % 2 != 0)
            return false;
        vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        if (arr[0] <= sum/2)
            dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum/2; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i])
                    dp[i][j] |= dp[i - 1][j - arr[i]];
            }
        }
        return dp[n - 1][sum/2];
    }
};