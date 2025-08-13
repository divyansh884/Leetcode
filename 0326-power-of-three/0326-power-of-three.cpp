class Solution {
public:
    bool isPowerOfThree(int n) {
        for(long long int i=0;;i++){
            if(n==pow(3,i))
            return true;
            else if(n<pow(3,i))
            break;
        }
        return false;
    }
};