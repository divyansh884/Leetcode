class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> vec;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        priority_queue<int, vector<int>, greater<int>> ind, val;
        ind.push(vec[0].second);
        val.push(vec[0].first);
        for (int i = 1; i < n; i++) {
            if (vec[i].first - vec[i - 1].first <= limit) {
                ind.push(vec[i].second);
                val.push(vec[i].first);
            } else {
                while (!val.empty()) {
                    ans[ind.top()] = val.top();
                    ind.pop();
                    val.pop();
                }
                ind.push(vec[i].second);
                val.push(vec[i].first);
            }
        }
        while (!val.empty()) {
            ans[ind.top()] = val.top();
            ind.pop();
            val.pop();
        }
        return ans;
    }
};