class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph1) {
        int V=graph1.size();
        vector<int> indeg(V,0);
        vector<int> ans;
        vector<vector<int>> graph(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<graph1[i].size();j++){
                graph[graph1[i][j]].push_back(i);
            }
        }
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
        sort(ans.begin(),ans.end());
        return ans;
    }
};