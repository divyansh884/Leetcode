class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (i >= n)
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];
        int sum = 0;
        int maxi = INT_MIN;
        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += nums[i + k];

            int curr = sum - f(i + k + 1, nums, dp);

            maxi = max(maxi, curr);
        }

        return dp[i] = maxi;
    }

    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MIN);

        int ans = f(0, nums, dp);

        if (ans > 0)
            return "Alice";

        if (ans < 0)
            return "Bob";

        return "Tie";
    }
};