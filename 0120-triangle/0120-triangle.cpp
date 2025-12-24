class Solution {
public:
int f(int i,int j,int m,vector<vector<int>>& grid,vector<vector<int>> &dp){
    if(i==m-1 && j<grid[i].size())
    return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int right=grid[i][j]+f(i+1,j+1,m,grid,dp);
    int down=grid[i][j]+f(i+1,j,m,grid,dp);
    return dp[i][j]= min(right,down);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int> (m,-1));
        return f(0,0,m,triangle,dp);
    }
};