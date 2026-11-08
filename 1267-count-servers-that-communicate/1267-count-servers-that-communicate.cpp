class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<pair<int, int>, bool> mp;
        for (int i = 0; i < n; i++) {
            queue<pair<int, int>> q;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
            if (q.size() <= 1)
                continue;
            while (!q.empty()) {
                mp[q.front()] = true;
                q.pop();
            }
        }
        for (int i = 0; i < m; i++) {
            queue<pair<int, int>> q;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1)
                    q.push({j, i});
            }
            if (q.size() <= 1)
                continue;
            while (!q.empty()) {
                mp[q.front()] = true;
                q.pop();
            }
        }
        return mp.size();
    }
};