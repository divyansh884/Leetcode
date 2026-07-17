class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
		for (auto it: edges) {
			adj[it[1]].push_back(it[0]);
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
		if(ans.size()!=V)
        return {};
        return ans;
    }
};