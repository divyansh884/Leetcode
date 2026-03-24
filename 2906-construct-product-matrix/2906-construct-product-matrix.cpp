class Solution {
public:
    int mod = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 1)),
            sufix(m, vector<int>(n, 1)), ans(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j]=(grid[i][j]%mod);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j - 1 >= 0)
                    prefix[i][j] = prefix[i][j - 1];
                else {
                    if (i - 1 >= 0)
                        prefix[i][j] = prefix[i - 1][n - 1];
                    else
                        prefix[i][j] = 1;
                }

                prefix[i][j] = (prefix[i][j] * grid[i][j]) % mod;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j + 1 < n)
                    sufix[i][j] = sufix[i][j + 1];
                else {
                    if (i + 1 < m)
                        sufix[i][j] = sufix[i + 1][0];
                    else
                        sufix[i][j] = 1;
                }

                sufix[i][j] = (sufix[i][j] * grid[i][j]) % mod;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int left, right;
                if (j - 1 >= 0)
                    left = prefix[i][j - 1];
                else if (i - 1 >= 0)
                    left = prefix[i - 1][n - 1];
                else
                    left = 1;
                if (j + 1 < n)
                    right = sufix[i][j + 1];
                else if (i + 1 < m)
                    right = sufix[i + 1][0];
                else
                    right = 1;

                ans[i][j] = (left * right) % mod;
            }
        }

        return ans;
    }
};