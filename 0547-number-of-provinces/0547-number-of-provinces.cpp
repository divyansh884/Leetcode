class Solution {
public:
 void f(int node,vector<vector<int>>& adj,vector<int> &vis,int n){
      vis[node]=1;
      for(int i=0;i<adj[node].size();i++){
          if(!vis[adj[node][i]])
          f(adj[node][i],adj,vis,n);
      }
  }
    int findCircleNum(vector<vector<int>>& isConnected){
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                f(i,adj,vis,n);
            }
        }
        return count;
    }
};