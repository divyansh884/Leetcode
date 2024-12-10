class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            char check= strs[0][i];
            bool see= true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=check){
                    see=false;
                    break;
                }
            }
            if(see)
            ans+=check;
            else
            break;
        }
        return ans;
    }
};