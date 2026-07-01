class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost, int source,
                                      int target) {
        priority_queue<vector<long long>, vector<vector<long long>>,
                       greater<vector<long long>>>
            pq;
        vector<vector<pair<long long, long long>>> adj(n);
        for (long long i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<long long> dist(n, -1);
        pq.push({0, -1LL * power, source});
        while (!pq.empty()) {
            long long wt = pq.top()[0];
            long long pp = -1 * pq.top()[1];
            long long node = pq.top()[2];
            pq.pop();
            if (pp <= dist[node]) {
                continue;
            }
            dist[node] = pp;
            if (node == target) {
                return {wt, pp};
            }
            if (pp - cost[node] >= 0) {
                for (auto it : adj[node]) {
                    pq.push({wt + it.second, -1 * (pp - cost[node]), it.first});
                }
            }
        }
        return {-1, -1};
    }
};