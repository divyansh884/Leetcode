class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high = 0;
        int low = *max_element(weights.begin(),weights.end()), n = weights.size();
        for (int i = 0; i < n; i++) {
            high += weights[i];
        }
        int sum = high;
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2, need = 1, cur = 0;
            for (int i = 0; i < weights.size(); cur += weights[i++])
                if (cur + weights[i] > mid)
                    cur = 0, need++;
            if (need <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};