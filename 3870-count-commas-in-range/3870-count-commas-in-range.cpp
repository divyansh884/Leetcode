class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        for(int i=1000;i<=n;i++){
            int num=i,cnt=0;
            while(num!=0){
                if(cnt==3){
                    ans++;
                    cnt=0;
                }
                cnt++;
                num/=10;
            }
        }
        return ans;
    }
};