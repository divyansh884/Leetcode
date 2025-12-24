class Solution {
public:
int f(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp){
    if(i==m-1 && j==n-1)
    return grid[i][j];
    if(i>=m || j>=n)
    return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int right=grid[i][j]+f(i,j+1,m,n,grid,dp);
    int down=grid[i][j]+f(i+1,j,m,n,grid,dp);
    return dp[i][j]= min(right,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,m,n,grid,dp);
    }
};