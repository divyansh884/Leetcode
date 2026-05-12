class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int sum = 0, n = tasks.size();
        int low = -1e9;
        for (int i = 0; i < n; i++) {
            sum += tasks[i][0];
            low = max(low, tasks[i][1]);
            tasks[i].push_back(tasks[i][1] - tasks[i][0]);
            swap(tasks[i][0], tasks[i][2]);
        }
        sort(tasks.rbegin(), tasks.rend());
        int high = low + sum;
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool check = true;
            int ene = mid;
            for (int i = 0; i < n; i++) {
                if (ene >= tasks[i][1]) {
                    ene -= tasks[i][2];
                } else {
                    check = false;
                    break;
                }
            }
            if (check) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};