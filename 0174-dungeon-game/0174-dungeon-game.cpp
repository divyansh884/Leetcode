class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<vector<int>>& dungeon) {
        if (i >= n || j >= m)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == n - 1 && j == m - 1)
            return dp[i][j] = max(1, 1 - dungeon[i][j]);
        int need = min(dfs(i + 1, j, dungeon),
                       dfs(i, j + 1, dungeon));
        return dp[i][j] = max(1, need - dungeon[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        dp.assign(n, vector<int>(m, -1));
        return dfs(0, 0, dungeon);
    }
};