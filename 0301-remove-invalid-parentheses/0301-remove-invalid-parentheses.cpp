class Solution {
public:
    bool check(string& s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') cnt++;
            else if (c == ')') {
                if (cnt == 0) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
    void f(int i, string& curr, string& s, int remove,
           unordered_set<string>& ans) {
        if (i == s.size()) {
            if (remove == 0 && check(curr)) {
                ans.insert(curr);
            }
            return;
        }
        if (remove > 0) {
            f(i + 1, curr, s, remove - 1, ans);
        }
        curr.push_back(s[i]);
        f(i + 1, curr, s, remove, ans);
        curr.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        int remove = left + right;
        unordered_set<string> st;
        string curr = "";
        f(0, curr, s, remove, st);
        return vector<string>(st.begin(), st.end());
    }
};