class Solution {
public:
    int fe(int tar, vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == tar)
                return mid;
            else if (arr[mid] > tar)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    bool f(int i, int k, vector<int>& st, vector<vector<int>>& dp) {
        int n = st.size();
        if (i == n - 1)
            return true;
        if (dp[i][k] != -1)
            return dp[i][k];
        bool take1 = false;
        bool take2 = false;
        bool take3 = false;
        int num = st[i];
        int first = fe(num + k - 1, st);
        if (k > 1 && first != -1)
            take1 = f(first, k - 1, st, dp);

        first = fe(num + k, st);
        if (first != -1)
            take3 = f(first, k, st, dp);

        first = fe(num + k + 1, st);
        if (first != -1)
            take2 = f(first, k + 1, st, dp);
        return dp[i][k] = take1 || take2 || take3;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        if (stones[1] != 1)
            return false;
        return f(1, 1, stones, dp);
    }
};