class Solution {
public:
void check(vector<vector<int> >&vec,int i,int j,int row,int col){
		if(vec[i][j]==1){
			vec[i][j]=-1;
			if(i>1)
				check(vec,i-1,j,row,col);
			if(j>1)
				check(vec,i,j-1,row,col);
			if(i+1<row)
				check(vec,i+1,j,row,col);
			if(j+1<col)
				check(vec,i,j+1,row,col);
		}
}
    int numEnclaves(vector<vector<int>>& board) {
        int i,j;
        int row=board.size();
        if(!row)
        	return 0;
        int col=board[0].size();
        for(i=0;i<row;i++){
			check(board,i,0,row,col);
			if(col>1)
				check(board,i,col-1,row,col);
		}
		for(j=1;j+1<col;j++){
			check(board,0,j,row,col);
			if(row>1)
				check(board,row-1,j,row,col);
		}
        int cnt=0;
        for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]==1)
					cnt++;
        return cnt;
    }
};