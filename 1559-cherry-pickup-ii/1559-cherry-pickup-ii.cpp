class Solution {
public:
int f(int i,int j1, int j2,vector<vector<int>>& grid,int n,vector<vector<vector<int>>> &dp){
    if(j1<0 | j2<0 || j1>=n|| j2>=n)
    return -1e8;
    if(i>=grid.size())
    return 0;
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi=0;
    for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
            int sum=0;
            if(j1==j2)sum+= grid[i][j1]+ f(i+1,j1+di,j2+dj,grid,n,dp);
            else
            sum+=grid[i][j1]+grid[i][j2]+ f(i+1,j1+di,j2+dj,grid,n,dp);
            maxi=max(maxi,sum);
        }
    }
    return dp[i][j1][j2]=maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(n,vector<int>(n,-1)));
        return f(0,0,n-1,grid,n,dp);
    }
};