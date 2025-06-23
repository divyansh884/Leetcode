class Solution {
public:
bool bfs(int ind,vector<vector<int>>& graph,vector<int> &vis, int col){
    vis[ind]=col;
    for(int i=0;i<graph[ind].size();i++){
        if(vis[graph[ind][i]]==-1){
            if(!bfs(graph[ind][i],graph,vis,!col))
            return false;
        }
        else if(vis[graph[ind][i]]==col)
        return false;
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