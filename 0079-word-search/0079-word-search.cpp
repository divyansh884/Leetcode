class Solution {
public:
    bool f(int i, int j, vector<vector<char>>& bb, string& word, int index) {
        if (index == word.size()) {
            return true;
        }
        char temp=bb[i][j];
        bb[i][j]='#';
        bool tt = false;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int index1 = 0; index1 < 4; index1++) {
            int newx = i + dx[index1];
            int newy = j + dy[index1];
            if (newx < bb.size() && newy < bb[0].size() && newx >= 0 &&
                newy >= 0) {
                if (bb[newx][newy] == word[index]) {
                   if(f(newx,newy,bb,word,index+1))
                        return true;
                }
            }
        }
        bb[i][j]=temp;
        return tt;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (f(i, j, board, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};
