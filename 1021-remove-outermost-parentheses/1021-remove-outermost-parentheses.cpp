class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if( s[i]=='('){
            st.push(s[i]);
            if(st.size()>1)
            ans+=s[i];
            }
            else{
                if(st.size()==1){
                    st.pop();
                }
                else{
                    st.pop();
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};