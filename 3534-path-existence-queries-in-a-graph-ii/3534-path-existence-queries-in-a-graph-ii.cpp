class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<pair<int, int>> ac;
        for (int i = 0; i < n; i++) {
            ac.push_back({nums[i], i});
        }
        sort(ac.begin(), ac.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[ac[i].second] = i;
        }

        int LOG = 20;
        vector<vector<int>> up(n, vector<int>(LOG, 0));
        
        for (int i = 0; i < n; i++) {
            int target = ac[i].first + maxDiff;
            int low = i;
            int high = n - 1;
            int best = i;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (ac[mid].first <= target) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            up[i][0] = best;
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<vector<pair<int, int>>> vec;
        vector<pair<int, int>> temp;
        temp.push_back({ac[0].first, ac[0].second});
        for (int i = 1; i < n; i++) {
            int node = ac[i].second;
            int cal = ac[i].first;
            if (abs(temp.back().first - cal) <= maxDiff) {
                temp.push_back({cal, node});
            } else {
                vec.push_back(temp);
                temp.clear();
                temp.push_back({cal, node});
            }
        }
        vec.push_back(temp);

        vector<int> mp(n);
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].size(); j++) {
                mp[vec[i][j].second] = i;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            
            if (mp[u] == mp[v]) {
                if (u == v) {
                    ans.push_back(0);
                } else {
                    int num1 = nums[u];
                    int num2 = nums[v];
                    if (abs(num1 - num2) <= maxDiff) {
                        ans.push_back(1);
                    } else if (maxDiff == 0) {
                        ans.push_back(1);
                    } else if (maxDiff == 1) {
                        ans.push_back(abs(num1 - num2));
                    } else {
                        int start_idx = (num1 < num2) ? pos[u] : pos[v];
                        int target_val = max(num1, num2);
                        int curr = start_idx;
                        int steps = 0;
                        
                        for (int j = LOG - 1; j >= 0; j--) {
                            if (ac[up[curr][j]].first < target_val) {
                                curr = up[curr][j];
                                steps += (1 << j);
                            }
                        }
                        ans.push_back(steps + 1);
                    }
                }
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};