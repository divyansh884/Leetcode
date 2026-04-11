class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for (auto it : mp) {
            if (mp[it.first].size() < 3)
                continue;
            int ind1 = mp[it.first][0], ind2 = mp[it.first][1],
                ind3 = mp[it.first][2];
            ans = min(ans,
                      abs(ind1 - ind2) + abs(ind2 - ind3) + abs(ind3 - ind1));
            int j = 3;
            while (j < mp[it.first].size()) {
                ind1 = ind2;
                ind2 = ind3;
                ind3 = mp[it.first][j];
                ans = min(ans, abs(ind1 - ind2) + abs(ind2 - ind3) +
                                   abs(ind3 - ind1));
                j++;
            }
        }
        if (ans == 1e9)
            return -1;
        return ans;
    }
};