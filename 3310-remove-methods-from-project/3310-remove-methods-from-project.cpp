class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> ans;
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(k);
        vis[k] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        bool check = false;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
                for (auto it : adj[i]) {
                    if (vis[it]) {
                        check = true;
                    }
                }
            }
        }
        if(!check)
        return ans;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};