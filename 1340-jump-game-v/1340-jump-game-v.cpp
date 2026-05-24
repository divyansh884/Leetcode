class Solution {
public:
    int f(int i, vector<int>& arr, int& d, vector<int>& dp) {
        if (i + 1 < arr.size() && arr[i] <= arr[i + 1]) {
            if (i - 1 >= 0 && arr[i] <= arr[i - 1])
                return 1;
            else if (i == 0)
                return 1;
        }
        if (i == arr.size() - 1) {
            if (i - 1 >= 0 && arr[i] <= arr[i - 1])
                return 1;
        }
        if (dp[i] != -1)
            return dp[i];
        bool cadd = true, csub = true;
        int add = 0;
        for (int x = 1; x <= d; x++) {
            if (cadd && i + x < arr.size() && arr[i] > arr[i + x]) {
                int cnt = 1 + f(i + x, arr, d, dp);
                add = max(add, cnt);
            } else if (i+x<arr.size() && arr[i] <= arr[i+x])
                cadd = false;
            if (csub && i - x >= 0 && arr[i] > arr[i - x]) {
                int cnt = 1 + f(i - x, arr, d, dp);
                add = max(add, cnt);
            } else if (i-x>=0 && arr[i] <= arr[i-x])
                csub = false;
            if (!cadd && !csub)
                break;
        }
        return dp[i] = add;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        if (n == 1)
            return 1;
        vector<int> dp(n, -1);
        int ans = 1;
        for (int i = 0; i < arr.size(); i++) {
            ans = max(ans, f(i, arr, d, dp));
        }
        return ans;
    }
};