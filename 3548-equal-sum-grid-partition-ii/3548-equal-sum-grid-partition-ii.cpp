class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        unordered_map<int, int> bottom, top;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bottom[grid[i][j]]++;
                total += grid[i][j];
            }
        }
        long long topSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                top[val]++;
                bottom[val]--;
                if (bottom[val] == 0)
                    bottom.erase(val);
                topSum += val;
            }
            long long bottomSum = total - topSum;
            if (topSum == bottomSum)
                return true;
            long long diff = abs(topSum - bottomSum);
            if(diff<=100000){
            if (topSum > bottomSum) {
                if (top.count(diff) && i != 0 && n != 1)
                    return true;
                if ((i == 0 || n == 1) &&
                    (grid[0][0] == diff || grid[0][n - 1] == diff || grid[i][0]==diff 
                    || grid[i][n-1]==diff))
                    return true;
            } else {
                if (bottom.count(diff) && i + 1 != m - 1 && n != 1)
                    return true;
                if ((i + 1 == m - 1 || n == 1) &&
                    (grid[m - 1][0] == diff || grid[m - 1][n - 1] == diff || grid[i+1][0]==diff || grid[i+1][n-1]==diff))
                    return true;
            }
            }
        }
        top.clear();
        bottom.clear();
        total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bottom[grid[i][j]]++;
                total += grid[i][j];
            }
        }
        long long leftSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                int val = grid[i][j];
                top[val]++;
                bottom[val]--;
                if (bottom[val] == 0)
                    bottom.erase(val);
                leftSum += val;
            }
            long long rightSum = total - leftSum;
            if (leftSum == rightSum)
                return true;
            long long diff = abs(leftSum - rightSum);
            if(diff<=100000){
            if (leftSum > rightSum) {
                if (top.count(diff) && j != 0 && m != 1)
                    return true;
                if ((j == 0 || m == 1) &&
                    (grid[0][0] == diff || grid[m - 1][0] == diff || grid[0][j]==diff || grid[m-1][j]==diff))
                    return true;
            } else {
                if (bottom.count(diff) && j + 1 != n - 1 && m != 1)
                    return true;
                if ((j + 1 == n - 1 || m == 1) &&
                    (grid[0][n - 1] == diff || grid[m - 1][n - 1] == diff || grid[0][j+1]==diff|| grid[m-1][j+1]==diff))
                    return true;
            }
            }
        }
        return false;
    }
};