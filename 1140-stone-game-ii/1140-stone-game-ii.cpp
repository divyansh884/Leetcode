class Solution {
public:
    int f(int i, int check, int m, vector<int>& arr,
          vector<vector<vector<int>>>& dp) {

        if (i >= arr.size())
            return 0;

        if (dp[i][check][m] != -1)
            return dp[i][check][m];

        int n = arr.size();
        int take = 0;
        int sum = 0;

        for (int j = i; j < min(n, i + 2 * m); j++) {

            sum += arr[j];

            if (check) {
                int temp = sum + f(
                    j + 1,
                    0,
                    max(m, j - i + 1),
                    arr,
                    dp
                );
                take = max(take, temp);
            }
            else {
                int temp = f(
                    j + 1,
                    1,
                    max(m, j - i + 1),
                    arr,
                    dp
                );
                 if (j == i)
                    take = temp;
                else
                    take = min(take, temp);
            }
        }

        return dp[i][check][m] = take;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2,
                vector<int>(2 * n + 1, -1)
            )
        );

        return f(0, 1, 1, piles, dp);
    }
};