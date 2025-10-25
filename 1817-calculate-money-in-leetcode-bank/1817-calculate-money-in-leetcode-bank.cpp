class Solution {
public:
    int totalMoney(int n) {
        int count = 0;
        int sum = 0;
        int mod = 7;
        for (int i = 1; i <=n; i++) {
            if(i%7!=0)
            sum += (i % mod) + count;
            if (i % 7 == 0) {
                sum+=7+count;
                mod = i;
                count++;
            }
        }
        return sum;
    }
};