class Solution {
public:
void bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,vector<vector<int>>& te,int m,int n,int &cnt){
    queue<vector<int>> q;
    for(int i=0;i<te.size();i++){
        q.push(te[i]);
    }
    q.push({-1,-1});
    while(!q.empty()){
        vector<int> temp=q.front();
        q.pop();
        if(temp[0]==-1 && temp[1]==-1){
        cnt++;
        if(!q.empty())
        q.push({-1,-1});
        }
        else{
        grid[temp[0]][temp[1]]=2;
        if(temp[0]-1>=0){
        if(grid[temp[0]-1][temp[1]]==1  && !vis[temp[0]-1][temp[1]]) {
            q.push({temp[0]-1,temp[1]});
            vis[temp[0]-1][temp[1]]=1;
        }
        }
        if(temp[1]+1<m){
        if(grid[temp[0]][temp[1]+1]==1  && !vis[temp[0]][temp[1]+1]) {
            q.push({temp[0],temp[1]+1});
            vis[temp[0]][temp[1]+1]=1;
        }
        }
         if(temp[0]+1<n){
        if(grid[temp[0]+1][temp[1]]==1  && !vis[temp[0]+1][temp[1]]) {
            q.push({temp[0]+1,temp[1]});
            vis[temp[0]+1][temp[1]]=1;
        }
        }
         if(temp[1]-1>=0){
        if(grid[temp[0]][temp[1]-1]==1  && !vis[temp[0]][temp[1]-1]) {
            q.push({temp[0],temp[1]-1});
            vis[temp[0]][temp[1]-1]=1;
        }
        }
        }
    }
}

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> te;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && vis[i][j]==0){
                    te.push_back({i,j});
                    vis[i][j]==1;
                }
            }
        }
        bfs(grid,vis,te,m,n,cnt);
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }
        return cnt-1;
    }
};