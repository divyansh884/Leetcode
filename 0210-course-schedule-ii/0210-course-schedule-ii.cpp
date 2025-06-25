class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
         vector<vector<int>> graph(V);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> indeg(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                indeg[graph[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0;i<graph[temp].size();i++){
                indeg[graph[temp][i]]--;
                if(indeg[graph[temp][i]]==0)q.push(graph[temp][i]);
            }
        }
       return ans.size() == V ? ans : vector<int>();
    }
};