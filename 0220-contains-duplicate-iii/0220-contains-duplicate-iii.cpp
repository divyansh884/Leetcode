class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int id, int vd) {
        int n = nums.size();
        if (id == 0) return false;

        map<long long, int> mp;

        int ed = min(n - 1, id);

        // Initial window: [1, ed]
        for (int i = 1; i <= ed; i++)
            mp[nums[i]]++;

        int st = 0;

        while (st < n) {
            long long l = 1LL * nums[st] - vd;
            long long r = 1LL * nums[st] + vd;

            auto it = mp.lower_bound(l);
            if (it != mp.end() && it->first <= r)
                return true;

            // Add next element to the window
            if (ed + 1 < n) {
                ed++;
                mp[nums[ed]]++;
            }

            // Remove the leftmost element of the current window
            int rem = st + 1;
            if (rem < n) {
                mp[nums[rem]]--;
                if (mp[nums[rem]] == 0)
                    mp.erase(nums[rem]);
            }

            st++;
        }

        return false;
    }
};