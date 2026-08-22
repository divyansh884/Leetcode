class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9) return (int)k;

        long long k_rem = k - 9;
        long long b = 1;
        long long p10 = 10;
        long long len = 2;

        while (true) {
            long long blocks = p10 - b;
            long long total_digits = blocks * 10 * len;
            
            if (k_rem > total_digits) {
                k_rem -= total_digits;
                b = p10;
                p10 *= 10;
                len++;
            } else {
                long long step = (k_rem - 1) / (10 * len);
                b += step;
                k_rem -= step * 10 * len;
                break;
            }
        }

        string re = "";
        if (b % 2 == 0) {
            for (int i = 0; i <= 9; i++) {
                re += to_string(b * 10 + i);
            }
        } else {
            for (int i = 9; i >= 0; i--) {
                re += to_string(b * 10 + i);
            }
        }

        return re[k_rem - 1] - '0';
    }
};