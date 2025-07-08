class Solution {
public:
int f(int i,int j,vector<vector<int>>& grid,int m,int n,vector<vector<int>> &dp){
    if(i==m-1 && j==n-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int down=1e9,left=1e9;
    if(i+1<m)
    down=grid[i][j]+ f(i+1,j,grid,m,n,dp);
    if(j+1<n){
        left=grid[i][j]+ f(i,j+1,grid,m,n,dp);
    }
    return dp[i][j]=min(left,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n,-1));
        return f(0,0,grid,m,n,dp);    
    }
};