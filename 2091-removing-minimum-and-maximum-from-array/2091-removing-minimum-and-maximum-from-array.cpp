class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minindex = -1, mini = INT_MAX;
        int maxindex = -1, maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mini > nums[i]) {
                mini = nums[i];
                minindex = i;
            }
            if (maxi < nums[i]) {
                maxi = nums[i];
                maxindex = i;
            }
        }
        int ans = max(maxindex, minindex) + 1;
        ans = min(ans, n - min(maxindex, minindex));
        ans =
            min(ans, min(maxindex, minindex) + 1 + n - max(maxindex, minindex));
        return ans;
    }
};