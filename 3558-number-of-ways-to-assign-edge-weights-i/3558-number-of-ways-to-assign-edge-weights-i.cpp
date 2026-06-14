class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int qpow(int x, int y) {
        int res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = 1ll * res * x % mod;
            }
            x = 1ll * x * x % mod;
        }
        return res;
    }
    int bfs_depth(int src, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> depth(n, -1);
        queue<int> q;

        q.push(src);
        depth[src] = 0;

        int mxDepth = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto child : adj[node]) {
                if (depth[child] == -1) {
                    depth[child] = depth[node] + 1;
                    mxDepth = max(mxDepth, depth[child]);
                    q.push(child);
                }
            }
        }

        return mxDepth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int max_dep = bfs_depth(1,g);
        return qpow(2, max_dep - 1);
    }
};