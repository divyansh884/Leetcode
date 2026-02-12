class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int, int> mp;
        int cnt = -1, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++;
                cnt = mp[s[j]];
                bool check = true;
                for (auto it : mp) {
                    if (it.second != cnt) {
                        check = false;
                        break;
                    }
                }
                if (check)
                    ans = max(ans, j - i + 1);
            }
            mp.clear();
            cnt = -1;
        }
        return ans;
    }
};