class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, n = nums.size();
        int ans = 1e9;
        int temp = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= nums[temp]) {
                ans = min(ans, nums[mid]);
                if (nums[mid] == nums[temp]) {
                    temp--;
                    high = temp;
                } else {
                    high = mid - 1;
                }
            } else
                low = mid + 1;
        }
        return ans;
    }
};