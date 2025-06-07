class Solution {
public:
    void backtrack(int open, int close, string &s, vector<string> &ans) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open > 0) {
            s.push_back('(');
            backtrack(open - 1, close, s, ans);
            s.pop_back();
        }
        if (close > open) {
            s.push_back(')');
            backtrack(open, close - 1, s, ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        backtrack(n, n, s, ans);
        return ans;
    }
};
