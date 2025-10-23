class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int high = nums.size() - 1, low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= ans) {
                while (low<nums.size() && nums[low] >= ans)
                    low++;
            } else {
                ans = nums[mid];
                high = mid - 1;
            }
        }
        return ans;
    }
};