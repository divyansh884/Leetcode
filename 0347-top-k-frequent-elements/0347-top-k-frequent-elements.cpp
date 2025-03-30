class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> store;
        for (int i = 0; i < nums.size(); i++) {
            store[nums[i]]++;
        }
        vector<int> ans;
        vector<pair<int, int>> v;
        for (auto it : store)
            v.push_back(make_pair(it.second, it.first));
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < v.size() && k != 0; i++) {
            ans.push_back(v[i].second);
            k--;
        }
        return ans;
    }
};