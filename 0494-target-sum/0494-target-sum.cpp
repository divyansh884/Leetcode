class Solution {
public:
    int n;
    const int OFFSET = 1000;

    int f(int i, int sum, vector<int>& nums, int target,
          vector<vector<int>>& dp) {

        if (i == n)
            return sum == target;

        if (dp[i][sum + OFFSET] != -1)
            return dp[i][sum + OFFSET];

        int add = f(i + 1, sum + nums[i], nums, target, dp);
        int sub = f(i + 1, sum - nums[i], nums, target, dp);

        return dp[i][sum + OFFSET] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2001, -1));

        return f(0, 0, nums, target, dp);
    }
};