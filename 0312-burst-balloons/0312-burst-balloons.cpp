class Solution {
public:
 int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if (i > j) return 0; 
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MIN;
        for (int k = i; k <=j; k++) {
            int cost= cuts[i-1]*cuts[k]*cuts[j+1]+f(i, k-1, cuts, dp) + f(k+1, j, cuts, dp);
            mini = max(mini, cost);
        }

        return dp[i][j] = mini;
    }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
                nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,n,nums,dp);
    }
};