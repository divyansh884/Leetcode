class Solution {
public:
    const int mod = 1e9 + 7;
    long long f(int i, int g1, int g2, vector<int>& nums,
                vector<vector<vector<int>>>& dp) {
        int n = nums.size();
        if (i == n) {
            if (g1 == g2 && g1 != 0)
                return 1;
            return 0;
        }
        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];
        long long take = (1LL * f(i + 1, gcd(g1, nums[i]), g2, nums, dp)) % mod;
        long long ntake =
            (1LL * f(i + 1, g1, gcd(g2, nums[i]), nums, dp)) % mod;
        long long take1 = (1LL * f(i + 1, g1, g2, nums, dp)) % mod;
        return dp[i][g1][g2] = (1LL*(take + take1 + ntake)) % mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxgcd = -1;
        for (int i = 0; i < n; i++) {
            maxgcd = max(maxgcd, nums[i]);
        }
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(maxgcd + 1, vector<int>(maxgcd + 1, -1)));
        return f(0, 0, 0, nums, dp);
    }
};