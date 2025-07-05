class Solution {
public:
void bfs(int i,vector<int> &dis,vector<vector<vector<int>>> &adj){
    queue<vector<int>> q;
    q.push({i,0});
    while(!q.empty()){
        int node=q.front()[0];
        int time=q.front()[1];
        q.pop();
        for(int it=0;it<adj[node].size();it++){
            int newtime=max(time,adj[node][it][1]);
            if(adj[node][it][1]<=newtime && adj[node][it][2]>=newtime  && newtime+1<=dis[adj[node][it][0]]){
                q.push({adj[node][it][0],newtime+1});
                dis[adj[node][it][0]]=newtime+1;
            }
        }
    }
}
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for( int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2],edges[i][3]});
        }
        if(n==1)
        return 0;
        vector<int> dis(n,1e9);
        dis[0]=0;
        bfs(0,dis,adj);
        if(dis[n-1]==1e9)
        return -1;
        return dis[n-1];
    }
};