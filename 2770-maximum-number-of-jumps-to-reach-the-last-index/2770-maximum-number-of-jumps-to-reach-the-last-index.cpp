class Solution {
public:
    int f(int i, int j, vector<int>& nums, int& target,
          vector<vector<int>>& dp) {
        if (j == nums.size() - 1) {
            if (abs(nums[j] - nums[i]) <= target)
                return 0;
            else
                return -1e9;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int take = -1e9, ntake = -1e9;
        if (abs(nums[j] - nums[i]) <= target)
            take = 1 + f(j, j + 1, nums, target, dp);
        ntake = f(i, j + 1, nums, target, dp);
        return dp[i][j] = max(take, ntake);
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        int ans = f(0, 1, nums, target, dp);
        if (ans < 0 || ans >= nums.size())
            return -1;
        return ans + 1;
    }
};