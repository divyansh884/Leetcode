class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (j == n || i == n)
            return 0;
        if (dp[i + 1][j] != -1)
            return dp[i + 1][j];
        int take = 0;
        if (i == -1 || nums[i] < nums[j]) {
            take = 1 + f(j, j + 1, nums, dp);
        }
        int ntake = f(i, j + 1, nums, dp);
        return dp[i+1][j] = max(take, ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(-1, 0, nums, dp);
    }
};