class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.'){
                    for(char it= '1';it<='9';it++){
                        if(isvalid(it,board,i,j)){
                            board[i][j]=it;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(char c,vector<vector<char>>& board, int row,int col){
        for(int i=0;i<9;i++){
            if(board[i][col]==c)
            return false;
            if(board[row][i]==c)
            return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            return false;
        }
        return true;
    }
};