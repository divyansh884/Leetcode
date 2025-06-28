class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mp;
        DisjointSet ds(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }
                else{
                    ds.unionByRank(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> ans(n),ans1;
         for(auto it: mp){
                ans[ds.findUPar(it.second)].push_back(it.first);
        }
        for(int i=0;i<n;i++){
            if(!ans[i].empty()){
                int par= ds.findUPar(mp[ans[i][0]]);
                sort(ans[i].begin(),ans[i].end());
                ans[i].insert(ans[i].begin(), accounts[par][0]);
                ans1.push_back(ans[i]);
            }
        }
        return ans1;
    }
};