class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topright) {
        long long ans = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (topright[i][0] >= bottomLeft[j][0] &&
                    topright[i][1] >= bottomLeft[j][1] &&
                    topright[j][0] >= bottomLeft[i][0] &&
                    topright[j][1] >= bottomLeft[i][1]) {
                    int x1 = max(bottomLeft[j][0], bottomLeft[i][0]);
                    int y1 = max(bottomLeft[j][1], bottomLeft[i][1]);
                    int x2 = min(topright[i][0], topright[j][0]);
                    int y2 = min(topright[i][1], topright[j][1]);
                    long long le = min(x2 - x1, y2 - y1);
                    ans = max(ans, le * le);
                }
            }
        }
        return ans;
    }
};