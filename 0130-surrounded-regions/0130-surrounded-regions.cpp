class Solution {
public:
    void bfsUtil(vector<vector<char>>& board, int i, int j, int rows, int cols) {
        // base case
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '*';

        // recursive DFS calls in all 4 directions
        bfsUtil(board, i + 1, j, rows, cols);
        bfsUtil(board, i, j + 1, rows, cols);
        bfsUtil(board, i - 1, j, rows, cols);
        bfsUtil(board, i, j - 1, rows, cols);
    }

    void traverseBorder(vector<vector<char>>& board, int rows, int cols) {
        // Top and bottom rows
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') {
                bfsUtil(board, 0, i, rows, cols);
            }
            if (board[rows - 1][i] == 'O') {
                bfsUtil(board, rows - 1, i, rows, cols);
            }
        }

        // Left and right columns
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                bfsUtil(board, i, 0, rows, cols);
            }
            if (board[i][cols - 1] == 'O') {
                bfsUtil(board, i, cols - 1, rows, cols);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();
        traverseBorder(board, rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};