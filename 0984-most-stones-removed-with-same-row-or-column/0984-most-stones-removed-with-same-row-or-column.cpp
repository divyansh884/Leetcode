
class DisjointSet{
public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }
};





class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow=0;
        int maxcol=0;
        for(int i = 0; i < n; i++){
            maxrow=max(maxrow,stones[i][0]);
            maxcol=max(maxcol,stones[i][1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int newrow=stones[i][0];
            int newcol=stones[i][1]+maxrow+1;
            ds.unionBySize(newrow,newcol);
            mp[newrow]=1;
            mp[newcol]=1;
        }
        int cnt=0;
        for( auto it:mp){
            if(ds.findUPar(it.first)==it.first)
            cnt++;
        }
        return n-cnt;
    }
};