class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for (auto &it : mp) {
            auto &v = it.second;
            if (v.size() < 3) continue;
            for (int i = 0; i + 2 < v.size(); i++) {
                int i1 = v[i];
                int i2 = v[i + 1];
                int i3 = v[i + 2];
                ans = min(ans, abs(i1 - i2) + abs(i2 - i3) + abs(i3 - i1));
            }
        }

        return (ans == 1e9) ? -1 : ans;
    }
};