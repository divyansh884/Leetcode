class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> comp;
        int st = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] > maxDiff) {
                comp.push_back({st, i});
                st = i + 1;
            }
        }
        comp.push_back({st, n - 1});
        for (int i = 0; i < queries.size(); i++) {
            int stt = queries[i][0];
            int ed = queries[i][1];
            int low = 0, high = comp.size() - 1;
            if (stt > ed) swap(stt, ed);
            bool check = false;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (comp[mid][0] <= stt && comp[mid][1] >= ed) {
                    check = true;
                    break;
                }
                if (comp[mid][0] > stt) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans.push_back(check);
        }
        return ans;
    }
};