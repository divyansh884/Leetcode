class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    long long dx1 = points[j][0] - points[i][0];
                    long long dy1 = points[j][1] - points[i][1];
                    long long dx2 = points[k][0] - points[i][0];
                    long long dy2 = points[k][1] - points[i][1];
                    if (dx1 * dy2 == dy1 * dx2)
                        cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};