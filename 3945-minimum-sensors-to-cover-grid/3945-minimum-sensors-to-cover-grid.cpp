class Solution {
public:
    int minSensors(int n, int m, int k) {
        vector<pair<int, int>> sensors;
        int cnt = 0, i = min(k, n - 1), j = min(k, m - 1);
        while (i < n) {
            while (j < m) {
                cnt++;
                if (j + (2 * k + 1) < m) {
                    j += (2 * k + 1);
                } else
                    j += k + 1;
            }
            j = min(k, m - 1);
            if (i + (2 * k + 1) < n) {
                i += (2 * k + 1);
            } else
                i += k + 1;
        }
        if (cnt == 0) {
            return 1;
        }
        return cnt;
    }
};