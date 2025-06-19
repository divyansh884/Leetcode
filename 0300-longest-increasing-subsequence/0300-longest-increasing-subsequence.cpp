class Solution {
public:
    int f(int index, vector<int> &nums, int n, int check, vector<vector<int>> &dp) {
        if (index >= n)
            return 0;
        
        if (dp[index][check + 1] != -1)
            return dp[index][check + 1];
        
        int take = 0, ntake = 0;
        
        ntake = f(index + 1, nums, n, check, dp);
        if (check == -1 || nums[check] < nums[index])
            take = 1 + f(index + 1, nums, n, index, dp);
        
        return dp[index][check + 1] = max(take, ntake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, nums, n, -1, dp);
    }
};
