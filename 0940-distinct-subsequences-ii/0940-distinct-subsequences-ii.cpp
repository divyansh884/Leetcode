class Solution {
public:
    const int mod = 1e9 + 7;

    int f(int i, string& s, vector<int>& dp) {
        if (i == s.size())
            return 1;

        if (dp[i] != -1)
            return dp[i];

        map<char, int> mp;
        int ans = 1;

        for (int j = i; j < s.size(); j++) {
            if (mp.find(s[j]) == mp.end()) {
                ans = (ans + f(j + 1, s, dp)) % mod;
            }
            mp[s[j]]++;
        }

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);

        return (f(0, s, dp) - 1 + mod) % mod;
    }
};