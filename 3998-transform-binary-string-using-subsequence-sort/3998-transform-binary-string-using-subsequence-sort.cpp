class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& str) {
        vector<bool> ans;
        int n = str.size();
        int m = s.size();
        int cnts0 = 0, cnt1s = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] == '0')
                cnts0++;
            else
                cnt1s++;
        }
        for (int i = 0; i < n; i++) {
            int cnt0 = 0, cnt1 = 0;
            for (int j = 0; j < m; j++) {
                if (str[i][j] == '0')
                    cnt0++;
                else if (str[i][j] == '1')
                    cnt1++;
            }
            if (cnt0 > cnts0 || cnt1 > cnt1s) {
                ans.push_back(false);
                continue;
            }
            bool check = true;
            for (int j = 0; j < m; j++) {
                if (str[i][j] == '?') {
                    if (cnt0 == cnts0 && cnt1s == cnt1) {
                        check = false;
                        break;
                    }
                    if (cnt0 != cnts0) {
                        cnt0++;
                        str[i][j] = '0';
                    } else if (cnt1 != cnt1s) {
                        cnt1++;
                        str[i][j] = '1';
                    }
                }
            }
            if (!check) {
                ans.push_back(check);
                continue;
            }
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (str[i][j] == '0' && s[j] == '1')
                    cnt++;
                else if (str[i][j] == '1' && s[j] == '0' && cnt == 0) {
                    check = false;
                    break;
                } else if (str[i][j] == '1' && s[j] == '0' && cnt != 0)
                    cnt--;
            }
            if (!check)
                ans.push_back(check);
            else {
                if (cnt == 0)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }
        return ans;
    }
};