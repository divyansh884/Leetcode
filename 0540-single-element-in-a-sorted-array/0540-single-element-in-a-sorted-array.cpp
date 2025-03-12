class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = nums.size() - 1;
        if (n == 1 || nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (mid != 0 && mid != n - 1) {
                if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                    return nums[mid];
            }
            if (mid % 2 == 0) {
                if (mid != 0 && mid != n - 1) {
                    if (nums[mid + 1] == nums[mid])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            } else {
                if (mid != 0 && mid != n - 1) {
                    if (nums[mid + 1] != nums[mid])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }
        return -1;
    }
};