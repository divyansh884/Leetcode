class Solution {
public:
    void f(int i, vector<vector<int>>& adj, vector<int>& check,
           vector<int>& vis) {
        check[i] = 1;
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    check[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> check(n, 0);
                f(i, adj, check, vis);
                int cnt = 0;
                for (auto it : check) {
                    if (it)
                        cnt++;
                }
                int no=0;
                for (auto it : edges) {
                    if (check[it[0]] && check[it[1]])
                    no++;
                }
                if(no==(cnt*(cnt-1))/2)
                ans++;
            }
        }
        return ans;
    }
};