class Solution {
public:
    bool sumGame(string num) {
        int lsum=0,lcnt=0;
        int n=num.size();
        for(int i=0;i<n/2;i++){
            if(num[i]=='?')
            lcnt++;
            else
            lsum+=(num[i]-'0');
        }
        int rsum=0,rcnt=0;
        for(int i=n/2;i<n;i++){
            if(num[i]=='?')
            rcnt++;
            else
            rsum+=(num[i]-'0');
        }
        if(rsum>lsum && rcnt>=lcnt)
        return true;
        if(lsum>rsum && lcnt>rcnt)
        return true;
        int cnt=abs(rcnt-lcnt);
        int sum=abs(rsum-lsum);
        int bcnt=cnt/2;
        int acnt=cnt-bcnt;
        if(acnt*9>sum || 9*bcnt<sum)
        return true;
        return false;

    }
};