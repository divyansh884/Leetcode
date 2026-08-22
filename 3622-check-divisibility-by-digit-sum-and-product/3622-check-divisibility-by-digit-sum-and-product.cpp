class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int dsum=0,psum=1;
        while(temp!=0){
            int num=temp%10;
            dsum+=num;
            psum*=num;
            temp/=10;
        }
        int re=n%(dsum+psum);
        return re==0;
    }
};