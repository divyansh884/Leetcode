class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occi,
                                                int freeStart, int freeEnd) {
        sort(occi.begin(), occi.end());
        vector<vector<int>> temp;
        int i = 0;
        int n = occi.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && occi[j][0] <= occi[i][1] + 1) {
                occi[i][1] = max(occi[i][1], occi[j][1]);
                j++;
            }
            temp.push_back({occi[i][0], occi[i][1]});
            i = j;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i][0] < freeStart && temp[i][1] <= freeEnd) {
                ans.push_back({temp[i][0], min(freeStart - 1, temp[i][1])});
            } else if (temp[i][0] >= freeStart && temp[i][1] > freeEnd) {
                ans.push_back({max(freeEnd + 1, temp[i][0]), temp[i][1]});
            } else if (temp[i][0] < freeStart && temp[i][1] > freeEnd) {
                ans.push_back({temp[i][0], freeStart - 1});
                ans.push_back({freeEnd + 1, temp[i][1]});
            }
        }
        return ans;
    }
};