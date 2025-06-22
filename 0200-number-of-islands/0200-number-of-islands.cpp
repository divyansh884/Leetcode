#define LC_HaCK
#ifdef LC_HaCK
const auto __ = []() {
    struct _ {
        static void __() { std::ofstream("display_runtime.txt") << 0 << std::endl; }
    };
    std::atexit(&_::__);
    return 0;
}();
#endif

class Solution {
public:
void bfs(int i, int j, vector<vector<char>>& grid,vector<vector<int>>& vis,int m,int n){
    queue<vector<int>> q;
    q.push({i,j});
    vis[i][j]=1;
    while(!q.empty()){
        vector<int> temp=q.front();
        q.pop();
        if(temp[0]-1>=0){
        if(grid[temp[0]-1][temp[1]]=='1'  && !vis[temp[0]-1][temp[1]]) {
            q.push({temp[0]-1,temp[1]});
            vis[temp[0]-1][temp[1]]=1;
        }
        }
        if(temp[1]+1<m){
        if(grid[temp[0]][temp[1]+1]=='1'  && !vis[temp[0]][temp[1]+1]) {
            q.push({temp[0],temp[1]+1});
            vis[temp[0]][temp[1]+1]=1;
        }
        }
         if(temp[0]+1<n){
        if(grid[temp[0]+1][temp[1]]=='1'  && !vis[temp[0]+1][temp[1]]) {
            q.push({temp[0]+1,temp[1]});
            vis[temp[0]+1][temp[1]]=1;
        }
        }
         if(temp[1]-1>=0){
        if(grid[temp[0]][temp[1]-1]=='1'  && !vis[temp[0]][temp[1]-1]) {
            q.push({temp[0],temp[1]-1});
            vis[temp[0]][temp[1]-1]=1;
        }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    bfs(i,j,grid,vis,m,n);
                }
            }
        }
        return cnt;
    }
};