class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> st;
        string ch(1, s[0]);
        vector<string> ans;
        st.insert(ch);
        ans.push_back(ch);
        string add = "";
        for (int i = 1; i < s.size(); i++) {
            string ch(1, s[i]);
            add += ch;
            if (st.count(add)) {
                continue;
            } else {
                st.insert(add);
                ans.push_back(add);
                add.clear();
            }
        }
        return ans;
    }
};