class Solution {
    vector<int> par, size;

public:
    int fup(int node) {
        if (node == par[node])
            return node;
        return par[node] = fup(par[node]);
    }
    void f(int u, int v) {
        int ulpu = fup(u);
        int ulpv = fup(v);
        if(ulpu==ulpv)
        return;
        if (size[ulpu] < size[ulpv]) {
            par[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        } else {
            par[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        par.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
        if (connections.size() < n - 1)
            return -1;
        for (int i = 0; i < connections.size(); i++) {
            f(connections[i][0], connections[i][1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (fup(0) != fup(i)) {
                ans++;
                f(0, i);
            }
        }
        return ans;
    }
};