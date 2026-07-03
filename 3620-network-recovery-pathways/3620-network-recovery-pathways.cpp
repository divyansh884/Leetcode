#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        if (edges.empty()) return -1;
        

        int max_weight = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            max_weight = max(max_weight, edge[2]);
        }
    
        auto canReach = [&](int min_bottleneck) {

            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            vector<long long> min_cost(n, 1e18);
            
            pq.push({0, 0});
            min_cost[0] = 0;
            
            while (!pq.empty()) {
                auto [cost_used, u] = pq.top();
                pq.pop();
                if (u == n - 1) return cost_used <= k;

                if (cost_used > min_cost[u]) continue;
                
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;

                    if (!online[v] || weight < min_bottleneck) continue;
                    
                    if (cost_used + weight < min_cost[v]) {
                        min_cost[v] = cost_used + weight;
                        pq.push({min_cost[v], v});
                    }
                }
            }
            return false;
        };

        int left = 0, right = max_weight;
        int best_bottleneck = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canReach(mid)) {
                best_bottleneck = mid;
                left = mid + 1;       
            } else {
                right = mid - 1;       
            }
        }
        
        return best_bottleneck;
    }
};