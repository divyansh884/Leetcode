class Solution {
public:
    string makeFancyString(string s) {
        char c=s[0];
        string ans="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
            cnt++;
            if(cnt<3)
            ans+=s[i];
            }
            else{
                cnt=1;
                ans+=s[i];
                c=s[i];
            }
        }
        return ans;
    }
};