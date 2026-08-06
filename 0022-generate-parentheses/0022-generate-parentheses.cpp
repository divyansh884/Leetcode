class Solution {
public:
bool check(string &s){
    stack<char> st;
    for(auto it: s){
        if(st.empty())
        st.push(it);
        else if(st.top()=='(' && it==')')
        st.pop();
        else
        st.push(it);
    }
    return st.empty();
}
    void f(vector<string>& ans, string& temp, int& n1,int& n2) {
        if (n1 == 0 && n2 == 0) {
            if(check(temp))
            ans.push_back(temp);
            return;
        }
        if (n1 != 0) {
            temp.push_back('(');
            n1--;
            f(ans, temp, n1, n2);
            temp.pop_back();
            n1++;
        }
        if (n2 !=0) {
                temp.push_back(')');
                n2--;
                f(ans, temp, n1, n2);
                temp.pop_back();
                n2++;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        int n1=n,n2=n;
        f(ans,temp,n1,n2);
        return ans;
    }
};