class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        vector<int> prefix(n, 0);
        vector<int> sufix(n, 0);
        vector<int> ans(n, 0); 

        if (n <= 1)
            return {0};
        for (int id = 0; id < n - 1; id++) {
            int i = 0, j = 0, cnt = 0;
            while (i < s[id].size() && j < s[id + 1].size() && s[id][i] == s[id + 1][j]) {
                cnt++; i++; j++;
            }
            prefix[id] = cnt;
        }
        for (int id = n - 1; id > 0; id--) {
            int i = 0, j = 0, cnt = 0;
            while (i < s[id].size() && j < s[id - 1].size() && s[id][i] == s[id - 1][j]) {
                cnt++; i++; j++;
            }
            sufix[id] = cnt;
        }
        vector<int> premax(n, 0), sufmax(n, 0);
        for (int i = 1; i < n; i++) {
            premax[i] = max(premax[i - 1], prefix[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            sufmax[i] = max(sufmax[i + 1], sufix[i + 1]);
        }

        ans[0] = sufmax[1];
        ans[n - 1] = premax[n - 2];

        for (int i = 1; i < n - 1; i++) {
            int id = 0, j = 0, cnt = 0;
            while (id < s[i - 1].size() && j < s[i + 1].size() && s[i - 1][id] == s[i + 1][j]) {
                cnt++; id++; j++;
            }
            ans[i] = max(cnt, max(premax[i - 1], sufmax[i + 1]));
        }

        return ans;
    }
};
