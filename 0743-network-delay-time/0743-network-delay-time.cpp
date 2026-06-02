class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int src) {
        vector<vector<pair<int, int>> > adj(n+1);
		for (int i = 0; i<edges.size(); i++) {
			adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
		}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
		vector<int> dis(n+1, 1e9);
		dis[src] = 0;
		q.push({0, src});
        while (!q.empty()) {
			int dist = q.top().first;
			int node = q.top().second;
			q.pop();
			if (dist<dis[node])
				continue;
			for (auto it: adj[node]) {
				if (dist + it.second<dis[it.first]) {
					dis[it.first] = dist + it.second;
					q.push({dist + it.second, it.first});
				}
			}
		}
        int ans=0;
        for (int i=1;i<=n;i++) {
			if (dis[i] == 1e9)
				return -1;
            else
            ans=max(ans,dis[i]);
		}
        return ans;
    }
};