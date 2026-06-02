class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : flights)
            adj[e[0]].push_back({e[1], e[2]});

        queue<vector<int>> q;
        q.push({0, src, 0}); // stops, node, cost

        vector<int> dis(n, 1e9);
        dis[src] = 0;

        while(!q.empty()) {

            auto cur = q.front();
            q.pop();

            int stops = cur[0];
            int node  = cur[1];
            int cost  = cur[2];

            if(stops > k) continue;

            for(auto &it : adj[node]) {

                int next = it.first;
                int wt   = it.second;

                if(cost + wt < dis[next]) {
                    dis[next] = cost + wt;
                    q.push({stops + 1, next, cost + wt});
                }
            }
        }

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};