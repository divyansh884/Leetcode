class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int cnt = 1;
        int step = 2;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += cnt;
            step++;
            if (step == 10) {
                cnt++;
                step = 2;
            }
        }
        return ans;
    }
};