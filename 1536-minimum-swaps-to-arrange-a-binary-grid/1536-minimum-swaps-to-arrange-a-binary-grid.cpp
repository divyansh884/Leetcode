class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> lastOne(n);

        for (int i = 0; i < n; i++) {
            int pos = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    pos = j;
            }
            lastOne[i] = pos;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int j = i;

            while (j < n && lastOne[j] > i)
                j++;

            if (j == n)
                return -1;

            while (j > i) {
                swap(lastOne[j], lastOne[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};