class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        vector<vector<int>> ans1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<long long, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                   long long need = (long long)target - ((long long)nums[i] + nums[j] + nums[k]);
                    if (mp.find(need) != mp.end())
                        ans.insert({nums[mp[need]], nums[i], nums[j], nums[k]});
                }
            }
            mp[nums[i]] = i;
        }
        for (auto it : ans) {
            ans1.push_back(it);
        }
        return ans1;
    }
};