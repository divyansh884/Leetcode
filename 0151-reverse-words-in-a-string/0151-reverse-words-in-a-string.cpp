class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        string t;
        for(long long int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ')
            t+=s[i];
            else if(t!=""&& s[i]==' '){
                reverse(t.begin(),t.end());
                ans+=t+' ';
                t="";
            }
        }
        reverse(t.begin(),t.end());
        ans+=t;
        int n= s.size()-1;
        while(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;   
    }
};