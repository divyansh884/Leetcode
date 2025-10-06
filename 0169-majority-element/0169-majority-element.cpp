class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for (auto it : mp) {
            if (it.second > n / 2)
            cnt = it.first;
        }
        return cnt;
    }
};