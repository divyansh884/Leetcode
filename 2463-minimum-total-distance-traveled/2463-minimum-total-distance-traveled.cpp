class Solution {
public:
    long long solve(int r, int f, vector<int>& robot,
                    vector<vector<int>>& factory,
                    vector<vector<long long>>& dp) {
        if (r == robot.size())
            return 0;
        if (f == factory.size())
            return 1e18;
        if (dp[r][f] != -1)
            return dp[r][f];
        long long ans = solve(r, f + 1, robot, factory, dp);
        long long cost = 0;
        int pos = factory[f][0];
        int cap = factory[f][1];
        for (int k = 0; k < cap && r + k < robot.size(); k++) {
            cost += abs(robot[r + k] - pos);
            ans = min(ans, cost + solve(r + k + 1, f + 1, robot, factory, dp));
        }
        return dp[r][f] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<long long>> dp(robot.size(),
                                     vector<long long>(factory.size(), -1));
        return solve(0, 0, robot, factory, dp);
    }
};