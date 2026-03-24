class Solution {
public:
    int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefix(m, vector<int>(n, 1)),
            sufix(m, vector<int>(n, 1)), ans(m, vector<int>(n, -1));
        int prev = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j]=grid[i][j]%mod;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] = prev;
                prev = (prev * grid[i][j]) % mod;
            }
        }
        prev = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                sufix[i][j] = prev;
                prev = (prev * grid[i][j]) % mod;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = (prefix[i][j] * sufix[i][j]) % mod;
            }
        }
        return ans;
    }
};