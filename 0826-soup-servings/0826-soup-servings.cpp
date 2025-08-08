class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;

    double solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (dp[a][b] > 0) return dp[a][b];

        return dp[a][b] = 0.25 * (
            solve(a - 100, b) +
            solve(a - 75, b - 25) +
            solve(a - 50, b - 50) +
            solve(a - 25, b - 75)
        );
    }

    double soupServings(int n) {
        if (n > 4800) return 1.0; 
        return solve(n, n);
    }
};
