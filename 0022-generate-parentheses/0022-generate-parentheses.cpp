class Solution {
public:
    void f(vector<string>& ans, string& temp, int n1,int n2) {
        if (n1 == 0 && n2 == 0) {
            ans.push_back(temp);
            return;
        }
        if(n1!=0){
            temp.push_back('(');
            f(ans,temp,n1-1,n2);
            temp.pop_back();
        }
        if(n2 > n1){
            temp.push_back(')');
            f(ans,temp,n1,n2-1);
            temp.pop_back();
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