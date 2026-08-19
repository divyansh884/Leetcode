class Solution {
public:
    static bool compare(string& s1, string& s2) {
        return s1.size() < s2.size();
    }

    bool comp(string& longer, string& shorter) {
        if (longer.size() != shorter.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < longer.size()) {
            if (j < shorter.size() && longer[i] == shorter[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == shorter.size();
    }

    int f(int i, int j, vector<string>& arr, vector<vector<int>>& dp) {
        if (j >= arr.size())
            return 0;

        if (dp[i + 1][j] != -1)
            return dp[i + 1][j];

        int take = 0;

        if (i == -1 || comp(arr[j], arr[i])) {
            take = 1 + f(j, j + 1, arr, dp);
        }

        int ntake = f(i, j + 1, arr, dp);

        return dp[i + 1][j] = max(take, ntake);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), compare);

        vector<vector<int>> dp(n + 1, vector<int>(n, -1));

        return f(-1, 0, words, dp);
    }
};