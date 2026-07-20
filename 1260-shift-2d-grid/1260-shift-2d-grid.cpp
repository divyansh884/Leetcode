class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k %= (m * n);

        while (k--) {
            int change = grid[m - 1][n - 1];

            for (int i = 0; i < m; i++) {
                int temp = grid[i][0];
                grid[i][0] = change;

                for (int j = 1; j < n; j++) {
                    int temp1 = grid[i][j];
                    grid[i][j] = temp;
                    temp = temp1;
                }

                change = temp;   
            }
        }

        return grid;
    }
};