class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        for(int i=0;i<pow(2,n);i++){
            string s="";
            bool check=true;
            int cnt=0;
            for(int j=0;j<n;j++){
                if((i&(1<<j))==0){
                    cnt++;
                    s+="0";
                }
                else{
                    cnt=0;
                    s+='1';
                }
                if(cnt>=2){
                    check=false;
                    break;
                }
            }
            if(check)
            ans.push_back(s);
        }
        return ans;
    }
};