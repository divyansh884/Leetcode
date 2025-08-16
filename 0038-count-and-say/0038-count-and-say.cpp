class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int step = 1; step < n; step++) {
            string temp = "";
            int count = 1;
            char ch = ans[0];

            for (int i = 1; i < ans.size(); i++) {
                if (ans[i] == ch) {
                    count++;
                } else {
                    temp += to_string(count);
                    temp += ch;
                    ch = ans[i];
                    count = 1;
                }
            }
            temp += to_string(count);
            temp += ch;

            ans = temp;
        }

        return ans;
    }
};
