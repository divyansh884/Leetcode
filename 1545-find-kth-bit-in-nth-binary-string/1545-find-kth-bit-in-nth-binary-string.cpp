class Solution {
public:
    char findKthBit(int n, int k) {
        string ans="0";
        bool carry=false;
        for(int i=0;i<n-1;i++){
            string add=ans;
            for( int j=0;j<ans.size();j++){
                if(add[j]=='1')
                add[j]='0';
                else
                add[j]='1';
            }
            reverse(add.begin(),add.end());
            ans+="1"+add;
        }
        return ans[k-1];
    }
};