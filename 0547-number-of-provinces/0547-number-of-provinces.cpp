class Solution {
public:
    void f(int i, vector<vector<int>>& adj, vector<int>& visited) {
        queue<int> q;
        visited[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }
        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                f(i, adj, visited);
            }
        }
        return cnt;
    }
};