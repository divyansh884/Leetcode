class Solution {
public:
    int solve(vector<int>& bloomDay, int mid, int k) {
        int ans = 0;
        int temp = 0;
        for (auto it : bloomDay) {
            if (it <= mid)
                temp++;
            else {
                temp = 0;
            }
            if (temp == k) {
                ans++;
                temp = 0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int temp = solve(bloomDay, mid, k);
            if (temp >= m) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};