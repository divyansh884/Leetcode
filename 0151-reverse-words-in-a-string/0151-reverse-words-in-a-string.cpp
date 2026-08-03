class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        int n=s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ')
                temp.push_back( s[i]);
            else {
                if (temp != "")
                    st.push(temp);
                temp = "";
            }
        }
        if (temp != "")
            st.push(temp);
        string ans = "";
        while (!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty())
            ans.push_back(' ');
        }
        return ans;
    }
};