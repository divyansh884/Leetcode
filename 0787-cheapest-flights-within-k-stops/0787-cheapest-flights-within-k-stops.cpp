class Solution {
public:
 void bfs(int i,vector<vector<pair<int,int>>> &graph,vector<int> &dis,int &k){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
      pq.push({0,i,0});
      while(!pq.empty()){
          int dist=pq.top()[2];
          int node=pq.top()[1];
          int step=pq.top()[0];
          pq.pop();
          if (step > k + 1) continue;
          for(int j=0;j<graph[node].size();j++){
              int newdis=dist+graph[node][j].second;
              if(newdis<dis[graph[node][j].first] && step+1<=k+1){
                  dis[graph[node][j].first]=newdis;
                  pq.push({step+1,graph[node][j].first,newdis});
              }
          }
      }
  }
    int findCheapestPrice(int V, vector<vector<int>>& edges, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(V);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> dis(V,1e9);
        dis[src]=0;
        bfs(src,graph,dis,k);
        if(dis[dst]==1e9)
        return -1;
        return dis[dst];
    }
};