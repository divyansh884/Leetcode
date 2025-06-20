class Solution {
public:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if (i + 1 == j) return 0; // no cuts in this segment
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost = cuts[j] - cuts[i] + f(i, k, cuts, dp) + f(k, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, -1));

        return f(0, c - 1, cuts, dp);
    }
};
