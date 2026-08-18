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

        if (ulpu == ulpv)
            return;

        if (size[ulpu] < size[ulpv]) {
            par[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else {
            par[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        par.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            par[i] = i;

        map<string, int> mp;
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (mp.find(email) == mp.end()) {
                    mp[email] = i;
                }
                else {
                    f(i, mp[email]);
                }
            }
        }
        map<int, vector<string>> temp;

        for (auto it : mp) {

            string email = it.first;
            int account = it.second;

            int parent = fup(account);

            temp[parent].push_back(email);
        }
        vector<vector<string>> ans;

        for (auto &it : temp) {

            int parent = it.first;

            vector<string> curr;

            curr.push_back(accounts[parent][0]);

            sort(it.second.begin(), it.second.end());

            for (auto &email : it.second)
                curr.push_back(email);

            ans.push_back(curr);
        }

        return ans;
    }
};