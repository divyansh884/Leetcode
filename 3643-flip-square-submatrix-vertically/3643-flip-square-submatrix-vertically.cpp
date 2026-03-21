class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int sx=x,ex=x+k-1;
        while(sx<=ex){
            for(int j=y;j<y+k;j++){
                swap(grid[sx][j],grid[ex][j]);
            }
            sx++;
            ex--;
        }
        return grid;
    }
};