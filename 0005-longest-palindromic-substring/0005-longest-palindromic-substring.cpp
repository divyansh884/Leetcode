class Solution {
public:
    string longestPalindrome(string s) {
        string ans(1, s[0]);
        string ans1(1, s[0]);
        for (int i = 0; i < s.size(); i++) {
            int low = i, high = i + 1;
            while (low >= 0 && high < s.size()) {
                if (s[low] == s[high]) {
                    ans = s.substr(low, high - low + 1);
                    if (ans1.size() < ans.size())
                        ans1 = ans;
                    low--;
                    high++;
                } else
                    break;
            }
            low = i, high = i;
            while (low >= 0 && high < s.size()) {
                if (s[low] == s[high]) {
                    ans = s.substr(low, high - low + 1);
                    if (ans1.size() < ans.size())
                        ans1 = ans;
                    low--;
                    high++;
                } else
                    break;
            }
        }
        return ans1;
    }
};
