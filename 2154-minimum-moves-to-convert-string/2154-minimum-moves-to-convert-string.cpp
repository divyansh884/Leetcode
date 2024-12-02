class Solution {
    public:
    int minimumMoves(string s) {
        int count=0,ans=0;
        int st=0;
        while(st<s.size()){
            if(s[st]=='X')
            break;
            else
            st++;
        }
        for(int i=st;i<s.size();i++){
            if(s[i]=='X'){
            count++;
            if(count>=3){
            ans+=1;
            count=0;
            }
            }
            else{
                if(count<3 && count!=0){
                count++;
                if(count>=3){
            ans+=1;
            count=0;
            }
                }
                else{
                    if(count!=0){
                    ans+=1;
                    count=0;
                    }
                }
            }
        }
        if(count!=0)
        ans+=1;
        return ans;
    }
};