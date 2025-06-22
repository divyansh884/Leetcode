class Solution {
public:
void bfs(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& vis,int &m,int &n,int &color,int &check){
    queue<vector<int>> q;
    q.push({i,j});
    vis[i][j]=1;
    while(!q.empty()){
        vector<int> temp=q.front();
        q.pop();
        grid[temp[0]][temp[1]]=color;
        if(temp[0]-1>=0){
        if(grid[temp[0]-1][temp[1]]==check  && !vis[temp[0]-1][temp[1]]) {
            q.push({temp[0]-1,temp[1]});
            vis[temp[0]-1][temp[1]]=1;
        }
        }
        if(temp[1]+1<m){
        if(grid[temp[0]][temp[1]+1]==check  && !vis[temp[0]][temp[1]+1]) {
            q.push({temp[0],temp[1]+1});
            vis[temp[0]][temp[1]+1]=1;
        }
        }
         if(temp[0]+1<n){
        if(grid[temp[0]+1][temp[1]]==check  && !vis[temp[0]+1][temp[1]]) {
            q.push({temp[0]+1,temp[1]});
            vis[temp[0]+1][temp[1]]=1;
        }
        }
         if(temp[1]-1>=0){
        if(grid[temp[0]][temp[1]-1]==check  && !vis[temp[0]][temp[1]-1]) {
            q.push({temp[0],temp[1]-1});
            vis[temp[0]][temp[1]-1]=1;
        }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int check=grid[sr][sc];
        bfs(sr,sc,grid,vis,m,n,color,check);
        return grid;
    }
};