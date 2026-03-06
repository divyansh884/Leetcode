class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                temp += s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z')
                temp += s[i];
            else if (s[i] >= '0' && s[i] <= '9')
            temp+=s[i];
            else{
                if(temp!="")
                st.push(temp);
                temp="";
            }
        }
        if(temp!="")
        st.push(temp);
        string ans="";
        while(!st.empty()){
            if(st.size()==1){
                ans+=st.top();
                st.pop();
            }
            else{
                ans+=st.top();
                st.pop();
                ans+=" ";
            }
        }
        return ans;
    }
};