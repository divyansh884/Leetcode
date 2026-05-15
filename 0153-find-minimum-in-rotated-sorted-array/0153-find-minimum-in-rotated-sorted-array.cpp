class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, n = nums.size();
        int ans=1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid]<=nums[n-1]) {
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};