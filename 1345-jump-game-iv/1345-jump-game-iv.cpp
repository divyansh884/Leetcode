class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> dis(n + 1, n + 1);
        queue<pair<int, int>> q;

        q.push({0, 0});
        dis[0] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            if (it.first + 1 < n && dis[it.first + 1] > it.second + 1) {
                q.push({it.first + 1, it.second + 1});
                dis[it.first + 1] = it.second + 1;
            }

            if (it.first - 1 >= 0 && dis[it.first - 1] > it.second + 1) {
                q.push({it.first - 1, it.second + 1});
                dis[it.first - 1] = it.second + 1;
            }
            for (auto itt : mp[arr[it.first]]) {
                if (itt != it.first && dis[itt] > it.second + 1) {
                    q.push({itt, it.second + 1});
                    dis[itt] = it.second + 1;
                }
            }
            mp[arr[it.first]].clear();
        }

        return dis[n - 1];
    }
};