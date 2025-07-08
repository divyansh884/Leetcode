class Solution {
public:
    void f(int i, int j, vector<vector<int>>& board,vector<vector<int>> &board2,int m,int n) {
        vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dy= {0, 1, 1, 1, 0, -1, -1, -1};
        int cnt1=0;
        for(int id=0;id<8;id++){
            int newx=i+dx[id];
            int newy=j+dy[id];
            if(newx>=0 && newy>=0 && newx<m && newy<n){
                if(board[newx][newy]==1)
                cnt1++;
            }
        }
        if(board[i][j]==1){
            if(cnt1<2 || cnt1>3)
            board2[i][j]=0;
        }
        else{
            if(cnt1==3)
            board2[i][j]=1;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> board2=board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                f(i,j,board,board2,m,n);
            }
        }
        board=board2;
    }
};