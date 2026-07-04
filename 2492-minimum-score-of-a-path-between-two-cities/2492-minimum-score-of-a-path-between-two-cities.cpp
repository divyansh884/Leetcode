class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        queue<int> q;
        vector<int> vis(n + 1, 0);
        q.push(1);
        vis[1] = 1;
        int ans = 1e9;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it.first]) {
                    vis[it.first] = 1;
                    ans = min(ans, it.second);
                    q.push(it.first);
                }
                else{
                    ans = min(ans, it.second);
                }
            }
        }
        return ans;
    }
};