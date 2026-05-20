class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        unordered_map<int, int> mp;
        vector<int> ans(n, 0);
        if (a[0] == b[0]) {
            mp[a[0]] = 2;
            ans[0] = 1;
        } else {
            mp[a[0]]++;
            mp[b[0]]++;
        }
        for (int i = 1; i < n; i++) {
            mp[a[i]]++;
            mp[b[i]]++;
            ans[i] = ans[i - 1];
            if (mp[a[i]] == 2) {
                ans[i]++;
            }
            if (mp[b[i]] == 2 && a[i]!=b[i]) {
                ans[i]++;
            }
        }
        return ans;
    }
};