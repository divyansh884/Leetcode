class Solution {
public:
    int jump(vector<int>& nums) {
        int maxind = 0;
        int prevmaxind = 0;
        int step = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (prevmaxind >= n - 1)
                break;

            if (i + nums[i] > maxind) {
                maxind = i + nums[i];
            }

            if (i == prevmaxind) {
                step++;
                prevmaxind = maxind;
            }
        }

        return step;
    }
};