class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long ans = 0;
        int n = skill.size(), m = mana.size();
        vector<long long> prefixsum(n);
        for (int i = 0; i < n; i++) {
            ans += mana[0] * skill[i];
            prefixsum[i] = ans;
        }
        for (int j = 1; j < m; j++) {
            ans = prefixsum[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                long long sub = skill[i] * mana[j];
                if (ans - sub < prefixsum[i]) {
                    ans = prefixsum[i];
                } else {
                    ans -= sub;
                }
            }
            for (int i = 0; i < n; i++) {
                ans += mana[j] * skill[i];
                prefixsum[i] = ans;
            }
        }
        return prefixsum[n-1];
    }
};