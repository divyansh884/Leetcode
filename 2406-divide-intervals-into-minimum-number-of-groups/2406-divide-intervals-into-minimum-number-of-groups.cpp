class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            if (pq.empty()) {
                pq.push(intervals[i][1]);
            }
            else if (pq.top() < intervals[i][0]) {
                pq.pop();
                pq.push(intervals[i][1]);
            }
            else {
                pq.push(intervals[i][1]);
            }

            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};