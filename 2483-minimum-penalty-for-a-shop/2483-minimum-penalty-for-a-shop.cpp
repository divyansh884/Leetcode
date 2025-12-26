class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> preN(n);
        vector<int> suffY(n);
        preN[0] = 0;
        suffY[n - 1] = 0;
        for (int i = 1; i < n; i++) {
            if (customers[i - 1] == 'N')
                preN[i] = 1 + preN[i - 1];
            else
                preN[i] = preN[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            if (customers[i + 1] == 'Y')
                suffY[i] = 1 + suffY[i + 1];
            else
                suffY[i] = suffY[i + 1];
        }
        int ans = 1e9;
        int re;
        for (int i = 0; i < n; i++) {
            if (preN[i] + suffY[i] < ans) {
                ans = preN[i] + suffY[i];
                re = i;
            }
        }
        if (suffY[0] == 0 && customers[0] != 'Y')
            return 0;
        if (re == 0 && customers[0] != 'Y')
            return 0;
        return re + 1;
    }
};