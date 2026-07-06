class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        int i = 0;
        int n = inter.size();
        vector<vector<int>> merge;
        while (i < n) {
            int j = i + 1;
            while (j < n) {
                if (inter[j][0] > inter[i][0] && inter[j][1] <= inter[i][1]) {
                    j++;
                } else if (inter[j][0] == inter[i][0]) {
                    inter[i][1] = max(inter[i][1], inter[j][1]);
                    j++;
                } else {
                    break;
                }
            }
            merge.push_back({inter[i][0], inter[i][1]});
            i = j;
        }
        return merge.size();
    }
};