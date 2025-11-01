class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "", temp = "";
        for (int i = n - 1; i >= 0; i--) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                temp += s[i];
            else {
                if (!temp.empty()) {
                    if (!ans.empty())
                        ans += " ";
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    temp.clear();
                }
            }
        }
        if (!temp.empty()) {
            if (!ans.empty())
                ans += " ";
            reverse(temp.begin(), temp.end());
            ans += temp;
            temp.clear();
        }
        return ans;
    }
};