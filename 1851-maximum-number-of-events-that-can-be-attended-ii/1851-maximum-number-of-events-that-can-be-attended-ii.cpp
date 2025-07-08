class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int findNextEvent(const vector<vector<int>>& events, int currEnd) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] > currEnd)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int f(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if (k == 0 || i >= events.size()) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int next = findNextEvent(events, events[i][1]);
        int take = events[i][2] + f(next, events, k - 1, dp);
        int skip = f(i + 1, events, k, dp);

        return dp[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), comp);
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return f(0, events, k, dp);
    }
};
