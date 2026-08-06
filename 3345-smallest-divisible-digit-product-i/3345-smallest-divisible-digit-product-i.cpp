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
        if (pro % t == 0)
            return n;
        int num = n % 10;
        pro /= num;
        n /= 10;
        while (num <= 9) {
            if ((pro * num) % t == 0)
                return n * 10 + num;
            num++;
        }
        return (n + 1) * 10;
    }
};