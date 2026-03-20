class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            vector<int> ll;
            for (int j = 0; j < m; j++) {
                if (i + k > n || j + k > m)
                    break;
                vector<int> diff;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        diff.push_back(grid[x][y]);
                    }
                }
                sort(diff.begin(), diff.end());
                int ins = INT_MAX;
                for (int it = 0; it < diff.size() - 1; it++) {
                    if (diff[it + 1] != diff[it])
                        ins = min(ins, abs(diff[it] - diff[it + 1]));
                }
                diff.clear();
                if (ins == INT_MAX)
                    ins = 0;
                ll.push_back(ins);
            }
            if (!ll.empty())
                ans.push_back(ll);
            ll.clear();
        }
        return ans;
    }
};