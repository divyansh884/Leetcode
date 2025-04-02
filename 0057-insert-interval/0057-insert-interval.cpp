class Solution {
public:
    vector<vector<int>> mergeans(vector<vector<int>>& intervals) {
        int i = 0;
        sort(intervals.begin(), intervals.end());
        while (i < intervals.size() - 1) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                if (intervals[i][1] < intervals[i + 1][1])
                    intervals[i][1] = intervals[i + 1][1];
                if (intervals[i][0] > intervals[i + 1][0])
                    intervals[i][0] = intervals[i + 1][0];
                intervals.erase(intervals.begin() + i + 1);
            } else
                i++;
        }
        return intervals;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return mergeans(intervals);
    }
};