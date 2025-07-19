class Solution {
public:
    bool canReach(int n, vector<vector<pair<int, int>>> &adj, vector<bool> &online, long long k, int minEdge) {
        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (cost > dist[u]) continue;

            for (auto &[v, c] : adj[u]) {
                if (c < minEdge) continue;
                if (!online[v] && v != n - 1) continue;
                if (dist[v] > cost + c) {
                    dist[v] = cost + c;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int minCost = INT_MAX, maxCost = INT_MIN;

        // Store input
        auto zalpernith = edges;

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            minCost = min(minCost, e[2]);
            maxCost = max(maxCost, e[2]);
        }

        int l = minCost, r = maxCost, ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (canReach(n, adj, online, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
