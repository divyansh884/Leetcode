class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1), dp1(n, -1);
        if (n <= 1) {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        if (n <= 2) {
            return dp[n - 1];
        }
        dp1[1] = nums[1];
        dp1[2] = max(nums[2], dp1[1]);
        for (int i = 3; i < n; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        return max(dp[n-2],dp1[n-1]);
    }
};