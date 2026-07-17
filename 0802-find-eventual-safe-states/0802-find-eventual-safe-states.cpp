class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>> adj(V);
		for (int i=0;i<V;i++) {
			for(auto it: graph[i]){
                adj[it].push_back(i);
            }
		}
		vector<int> indeg(V, 0);
		for (int i = 0; i<V; i++) {
			for (auto it: adj[i]) {
				indeg[it]++;
			}
		}
		vector<int> ans;
		queue<int> q;
		for (int i = 0; i<V; i++) {
			if (indeg[i] == 0)
				q.push(i);
		}
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			ans.push_back(node);
			for (auto it:adj[node]) {
				indeg[it]--;
				if (indeg[it] == 0)
					q.push(it);
			}
		}
        sort(ans.begin(),ans.end());
        return ans;
    }
};