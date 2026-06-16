class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else if(s[i]=='%'){
                if(result.size()>1)
                reverse(result.begin(),result.end());
            }
            else if(s[i]=='#'){
                string temp=result;
                result+=temp;
            }
            else
            result.push_back(s[i]);
        }
        return result;
    }
};