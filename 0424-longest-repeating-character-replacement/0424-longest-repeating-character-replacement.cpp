class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int ans = 0;
        while (j < s.size()) {
            mp[s[j]]++;
            int sum = 0;
            int maxi = 0;
            for (auto it : mp) {
                maxi = max(maxi, it.second);
                sum += it.second;
            }
            while (sum - maxi > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
                sum = 0;
                maxi = 0;
                for (auto it : mp) {
                    maxi = max(maxi, it.second);
                    sum += it.second;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};