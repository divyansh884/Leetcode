class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int i = 0; i < guards.size(); i++) {
            matrix[guards[i][0]][guards[i][1]] = 1;
        }
        for (int i = 0; i < walls.size(); i++) {
            matrix[walls[i][0]][walls[i][1]] = -1;
        }

        for (int i = 0; i < m; i++) {
            bool check = false;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && !check)
                    check = true;
                else if (matrix[i][j] == 0 && check)
                    matrix[i][j] = 2;
                else if (matrix[i][j] == -1 && check)
                    check = false;
            }
            check = false;
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == 1 && !check)
                    check = true;
                else if (matrix[i][j] == 0 && check)
                    matrix[i][j] = 2;
                else if (matrix[i][j] == -1 && check)
                    check = false;
            }
        }
        for (int i = 0; i < n; i++) {
            bool check = false;
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == 1 && !check)
                    check = true;
                else if (matrix[j][i] == 0 && check)
                    matrix[j][i] = 2;
                else if (matrix[j][i] == -1 && check)
                    check = false;
            }
            check = false;
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[j][i] == 1 && !check)
                    check = true;
                else if (matrix[j][i] == 0 && check)
                    matrix[j][i] = 2;
                else if (matrix[j][i] == -1 && check)
                    check = false;
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};