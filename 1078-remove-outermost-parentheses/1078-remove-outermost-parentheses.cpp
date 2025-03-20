class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        int cntf=0;
        int cntb=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(cntf==0 && cntb==0)
                cntf++;
                else{
                 cntf++;
                st.push(s[i]);
                }
            }
            else{
                cntb++;
                if(cntf==cntb){
                    cntf=0;
                    cntb=0;
                }
                else
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};