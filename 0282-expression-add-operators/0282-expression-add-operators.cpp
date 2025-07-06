class Solution {
public:
    void f(string &num, int target, vector<string> &ans, string path, int pos, long evaluated, long prevNum) {
        if (pos == num.size()) {
            if (evaluated == target) ans.push_back(path);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break; // skip numbers with leading 0
            string curStr = num.substr(pos, i - pos + 1);
            long curNum = stol(curStr);

            if (pos == 0) {
                // first number, no operator
                f(num, target, ans, curStr, i + 1, curNum, curNum);
            } else {
                f(num, target, ans, path + "+" + curStr, i + 1, evaluated + curNum, curNum);
                f(num, target, ans, path + "-" + curStr, i + 1, evaluated - curNum, -curNum);
                f(num, target, ans, path + "*" + curStr, i + 1, evaluated - prevNum + prevNum * curNum, prevNum * curNum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        f(num, target, ans, "", 0, 0, 0);
        return ans;
    }
};
