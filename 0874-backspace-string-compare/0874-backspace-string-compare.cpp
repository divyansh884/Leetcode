class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        stack<char> tt;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' && ss.size()!=0){
                ss.pop();
            }
            else if(s[i]!='#'){
                ss.push(s[i]);
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' && tt.size()!=0){
                tt.pop();
            }
            else if(t[i]!='#'){
                tt.push(t[i]);
            }
        }
        string ans1;
        string ans2;
        while(ss.size()!=0){
            ans1+=ss.top();
            ss.pop();
        }
        while(tt.size()!=0){
            ans2+=tt.top();
            tt.pop();
        }
        cout<<ans1<<" "<<ans2<<endl;
        return ans1==ans2;
    }
};