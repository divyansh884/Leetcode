class Solution {
public:
    string largestGoodInteger(string num) {
        char ch=num[0];
        int cnt=1,n=num.size(),chf=-1;
        for(int i=1;i<n;i++){
            if(num[i]==ch){
                cnt++;
                if(cnt==3){
                    chf=max(chf,num[i]-'0');
                }
            }
            else{
                cnt=1;
                ch=num[i];
            }
        }
        string ans="";
        if(chf==-1)
        return ans;
        for(int i=0;i<3;i++){
            ans+=(chf +'0');
        }
        return ans;
    }
};