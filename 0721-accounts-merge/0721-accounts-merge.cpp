class Solution {
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v)
            parent[v] = u;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < acc[i].size(); j++) {
                if (mp.find(acc[i][j]) == mp.end()) {
                    mp[acc[i][j]] = i;
                } else {
                    unite(i, mp[acc[i][j]]);
                }
            }
        }
        map<int, set<string>> fi;

        for (auto &it : mp) {
            int p = find(it.second);
            fi[p].insert(it.first);
        }

        vector<vector<string>> ans;

        for (auto &[key, st] : fi) {
            vector<string> temp;
            temp.push_back(acc[key][0]);

            for (auto &email : st)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};