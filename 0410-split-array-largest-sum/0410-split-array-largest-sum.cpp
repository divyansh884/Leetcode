class Solution {
public:
    bool check(vector<int>& nums, int k, int mid) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) {
                cnt++;
                sum = 0;
                continue;
            }
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                cnt++;
                sum = nums[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int high = 0, low = 0;
        for (int i = 0; i < nums.size(); i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(check(nums,k,mid))
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};