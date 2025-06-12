struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
class Solution {
public:
    bool solve(int index, int row, int col, vector<vector<char>>& board,
               string word, int n, unordered_map<pair<int,int>,bool,pair_hash> &mp) {
        if (index >= n){
            return true;
        }
        if (row < board.size() - 1) {
            if (board[row + 1][col] == word[index] && mp[{row+1,col}]!=true) {
                mp[{row+1,col}]=true;
                if(solve(index + 1, row + 1, col, board, word, n,mp))
                return true;
                mp[{row+1,col}]=false;
            }
        }
        if (row > 0) {
            if (board[row - 1][col] == word[index] && mp[{row-1,col}]!=true) {
                 mp[{row-1,col}]=true;
                if(solve(index + 1, row - 1, col, board, word, n,mp))
                return true;
                 mp[{row-1,col}]=false;
            }
        }
        if (col < board[row].size() - 1) {
            if (board[row][col + 1] == word[index]&& mp[{row,col+1}]!=true) {
                mp[{row,col+1}]=true;
                if(solve(index + 1, row, col + 1, board, word, n,mp))
                return true;
                mp[{row,col+1}]=false;
            }
        }
        if (col > 0) {
            if (board[row][col - 1] == word[index] && mp[{row,col-1}]!=true) {
                mp[{row,col-1}]=true;
                if(solve(index + 1, row, col - 1, board, word, n,mp))
                return true;
                mp[{row,col-1}]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = word.size();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if(board[i][j]==word[0]){
                unordered_map<pair<int,int>,bool,pair_hash> mp;
                mp[{i, j}] = true;
                if(solve(1, i, j, board, word, n,mp))
                return true;
                }
            }
        }
        reverse(word.begin(),word.end());
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if(board[i][j]==word[0]){
                unordered_map<pair<int,int>,bool,pair_hash> mp;
                mp[{i, j}] = true;
                if(solve(1, i, j, board, word, n,mp))
                return true;
                }
            }
        }
        return false;
    }
};