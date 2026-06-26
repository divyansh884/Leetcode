class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int id, int vd) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 1; i <= min(n - 1, id); i++) {
            mp[nums[i]]++;
        }
        int st = 0;
        int ed = min(n - 1, id);
        while (st < n) {
            int r = nums[st] + vd;
            int l = nums[st] - vd;
            auto it = mp.lower_bound(l);
            if (it != mp.end() && it->first <= r) {
                return true;
            }
            ed++;
            if (ed < n)
                mp[nums[ed]]++;
            st++;
            if (st < n)
                mp[nums[st]]--;
            if (st<n && mp[nums[st]] == 0) {
                mp.erase(nums[st]);
            }
        }
        return false;
    }
};