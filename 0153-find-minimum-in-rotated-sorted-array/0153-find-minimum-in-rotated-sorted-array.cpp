class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low +(high-low)/2;
            if(nums[low]<nums[mid] && nums[high]>nums[mid]){
                if(ans>nums[mid])
                ans=nums[mid];
                high=mid-1;
            }
            else if(nums[low]>nums[mid] && nums[high]<nums[mid]){
                if(ans>nums[mid])
                ans=nums[mid];
                low=mid+1;
            }
            else {
                 if(ans>nums[mid])
                ans=nums[mid];
                if(nums[low]<nums[high])
                high=mid-1;
                else
                low=low+1;
            }
        }
        return ans;
    }
};