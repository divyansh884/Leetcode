class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int n=strs.size();
        for(int i=0;i<n;i++){
            string re="";
            for( int j=0;j<strs[i].size();j++){
                if(j<ans.size() && ans[j]==strs[i][j])
                re+=ans[j];
                else
                break;
            }
            ans=re;
        }
        return ans;
    }
};