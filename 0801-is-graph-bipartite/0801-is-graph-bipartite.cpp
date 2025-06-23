class Solution {
public:
bool bfs(int i,vector<vector<int>>& graph,vector<int> &vis, int col){
    queue<int> q;
    q.push(i);
    vis[i]=col;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int j=0;j<graph[temp].size();j++){
            if(vis[graph[temp][j]]==-1){
                vis[graph[temp][j]]=!vis[temp];
                q.push(graph[temp][j]);
            }
            else if(vis[graph[temp][j]]==vis[temp])
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!bfs(i,graph,vis,0))
                return false;
            }
        }
        return true;
    }
};