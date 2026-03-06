class Solution {
public:
    bool check(int i, int j, vector<string>& temp, int& n) {
        int x = i, y = j;
        while (x >= 0) {
            if (temp[x][y] == 'Q')
                return false;
            x--;
        }
        x = i;
        y = j;
        while (x >= 0 && y >= 0) {
            if (temp[x][y] == 'Q')
                return false;
            y--;
            x--;
        }
        x = i;
        y = j;
        while (x >= 0 && y < n) {
            if (temp[x][y] == 'Q')
                return false;
            y++;
            x--;
        }
        return true;
    }
    void f(int i, vector<vector<string>>& ans, vector<string>& temp, int q,
           int& n) {
        if (i == n) {
                ans.push_back(temp);
            return;
        }
        for (int y = 0; y < n; y++) {
            if (check(i, y, temp, n)) {
                temp[i][y] = 'Q';
                f(i + 1, ans, temp, q - 1, n);
                temp[i][y] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<vector<string>> ans;
        f(0, ans, board, n, n);
        return ans;
    }
};