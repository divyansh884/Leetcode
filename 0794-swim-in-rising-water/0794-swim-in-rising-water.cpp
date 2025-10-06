class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        int n=grid.size();
        q.push({grid[0][0],0,0});
        int ans=grid[n-1][n-1];
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(n,-1));
        vis[0][0]=1;
        while(!q.empty()){
            int x=q.top()[1];
            int y=q.top()[2];
            int time=q.top()[0];
            q.pop();
            if(x==n-1 && y==n-1){
                ans=time;
                break;
            }
            for(int i=0;i<4;i++){
                int newx=x+dx[i],newy=y+dy[i];
                if(newx<n && newy<n && newx>=0 && newy>=0 && vis[newx][newy]==-1){
                    vis[newx][newy]=1;
                    q.push({max(grid[newx][newy],time),newx,newy});
                }
            }
        }
        return ans;

    }
};