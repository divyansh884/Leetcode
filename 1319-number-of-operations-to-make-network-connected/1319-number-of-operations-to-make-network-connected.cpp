class Solution {
    vector<int> parent, size;

public:
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBysize(int u, int v) {
         int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        if (connections.size() < n - 1)
            return -1;
        for (int i = 0; i < connections.size(); i++) {
            unionBysize(connections[i][0],connections[i][1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(findUPar(0)!=findUPar(i)){
                ans++;
                unionBysize(0,i);
            }
        }
        return ans;
    }
};