class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp = n;
        int pro = 1;
        while (temp != 0) {
            int e = temp % 10;
            pro *= e;
            temp /= 10;
        }
        if(pro%t==0)
        return n;
        int num = n % 10;
        pro/=num;
        n/=10;
        bool check = false;
        while (num < 10) {
            if ((pro*num) % t == 0) {
                check = true;
                break;
            }
            if (num != 10)
                num++;
        }
        if (check) {
            n = n * 10 + num;
            return n;
        }
        return (n * 10) + 10;
    }
};