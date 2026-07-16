class Solution {
public:
    void f(int node, vector<vector<int>>& dj, vector<int>& vis) {
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : dj[node]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                vis[i] = 1;
                f(i, adj, vis);
            }
        }
        return ans;
    }
};