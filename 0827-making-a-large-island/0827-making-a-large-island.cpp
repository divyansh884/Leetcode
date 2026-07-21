class DisjointSet {
public:
    vector<int> rank, parent, size;
    
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                        int node = i * n + j;
                        int adjNode = ni * n + nj;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                set<int> components;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                        components.insert(ds.findUPar(ni * n + nj));
                    }
                }
                int sum = 1;
                for (auto comp : components) {
                    sum += ds.size[comp];
                }
                maxi = max(maxi, sum);
            }
        }
        for (int i = 0; i < n * n; i++) {
            maxi = max(maxi, ds.size[ds.findUPar(i)]);
        }

        return maxi;
    }
};
