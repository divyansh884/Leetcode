class Solution {
    int MOD = 1000000007;

    int intPow(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

public:
    int f(int i, int sum, int &n, int &x,vector<vector<int>> &dp) {
        if (sum == n) return 1;
        if (sum > n) return 0;

        int p = intPow(i, x);
        if (sum + p > n) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take = f(i + 1, sum + p, n, x,dp) % MOD;
        int ntake = f(i + 1, sum, n, x,dp) % MOD;

        return dp[i][sum]=(take + ntake) % MOD; 
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1, 0, n, x,dp);
    }
};
