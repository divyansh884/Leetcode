class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && nums[mid]>target) {
                    high=mid-1;
                } else
                    low=mid+1;
            } else {
                if (nums[mid] < target && nums[high]>=target) {
                    low=mid+1;
                } else
                    high=mid-1;
            }
            
        }
        if(ans!=-1)return true;
        return false;
    }
};