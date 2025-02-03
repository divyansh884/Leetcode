class Solution {
public:
    int reverse(long long x) {
        long long n=0;
        
        while(x!=0){
        n= (n*10)+x%10;
        x=x/10;
        }
        if(n>=(-pow(2,31))&& n<(pow(2,31)-1))
        return n;
        else
        return 0;
    }
};