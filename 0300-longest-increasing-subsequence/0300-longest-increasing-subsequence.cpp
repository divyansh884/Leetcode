class Solution {
public:
    int f(int prev, int i, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == n) return 0;

        if (dp[prev + 1][i] != -1)
            return dp[prev + 1][i];

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + f(i, i + 1, n, nums, dp);
        }

        int ntake = f(prev, i + 1, n, nums, dp);

        return dp[prev + 1][i] = max(take, ntake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return f(-1, 0, n, nums, dp);
    }
};
