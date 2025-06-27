const int MOD = 1e9 + 7;

class Solution {
public:
    void bfs(int i, vector<vector<pair<int, int>>>& graph, vector<vector<long long>>& dis) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<>> pq;
        pq.push({0, i});

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            long long dist = top[0];
            int node = top[1];
            if(dist>dis[node][0]) continue;
            for (auto& [nbr, wt] : graph[node]) {
                long long newDist = dist + wt;

                if (newDist < dis[nbr][0]) {
                    dis[nbr][0] = newDist;
                    dis[nbr][1] = dis[node][1];
                    pq.push({newDist, nbr});
                } else if (newDist == dis[nbr][0]) {
                    dis[nbr][1] = (dis[nbr][1] + dis[node][1]) % MOD;
                }
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }

        vector<vector<long long>> dis(n, vector<long long>(2, 0));
        for (int i = 0; i < n; i++) dis[i][0] = 1e18;
        dis[0][0] = 0;
        dis[0][1] = 1;

        bfs(0, graph, dis);
        return dis[n - 1][1];
    }
};
