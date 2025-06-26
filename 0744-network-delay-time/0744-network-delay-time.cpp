class Solution {
public:
void bfs(int i,vector<vector<pair<int,int>>> &graph,vector<int> &dis){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push({0,i});
      while(!pq.empty()){
          int dist=pq.top().first;
          int node=pq.top().second;
          pq.pop();
          for(int j=0;j<graph[node].size();j++){
              int newdis=dist+graph[node][j].second;
              if(newdis<dis[graph[node][j].first]){
                  dis[graph[node][j].first]=newdis;
                  pq.push({newdis,graph[node][j].first});
              }
          }
      }
  }
    int networkDelayTime(vector<vector<int>>& edges, int V, int k) {
        vector<vector<pair<int,int>>> graph(V);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]-1].push_back({edges[i][1]-1,edges[i][2]});
        }
        vector<int> dis(V,1e9);
        dis[k-1]=0;
        bfs(k-1,graph,dis);
        int ans=0;
        for(auto it: dis){
            ans=max(ans,it);
        }
        if(ans==1e9)
        return -1;
        return ans;
    }
};