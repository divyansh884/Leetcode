class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int high = 0, low = INT_MAX;
        for (int i = 0; i < n; i++) {
            high = max(high, bloomDay[i]);
            low = min(low, bloomDay[i]);
        }
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0, bq = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    cnt++;
                    if (cnt == k) {
                        bq++;
                        cnt = 0;
                    }
                } else
                    cnt = 0;
            }
            if (bq >= m) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};