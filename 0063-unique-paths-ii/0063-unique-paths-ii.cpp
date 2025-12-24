class Solution {
public:
int f(int i,int j, int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
    if(i==m-1 && j==n-1)
    return 1;
    if(i>=m || j>=n)
    return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int take=0,ntake=0;
    if(j+1<n && obstacleGrid[i][j+1]!=1)
    take= f(i,j+1,m,n,obstacleGrid,dp);
    if(i+1<m && obstacleGrid[i+1][j]!=1)
    ntake= f(i+1,j,m,n,obstacleGrid,dp);
    return dp[i][j]=take+ntake;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
        return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,m,n,obstacleGrid,dp);
    }
};