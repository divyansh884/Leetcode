class Solution {
public:
    bool isHappy(int n) {
        if(n<10){
            if(n==1 || n==7)
        return true;
        return false;
        }
        int sum=0;
            while(n!=0){
            int k= n%10;
            sum+=pow(k,2);
            n/=10;
            }
        return isHappy(sum);
    }
};