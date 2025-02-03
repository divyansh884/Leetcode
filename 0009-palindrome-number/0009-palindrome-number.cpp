class Solution {
public:
    bool isPalindrome(long long x) {
        long long temp =x;
        long long k=0;
        while(x>0){
            k = k*10+x%10;
            x /=10;
        }
        if(k==temp)
        return true;
        else
        return false;
    }
};