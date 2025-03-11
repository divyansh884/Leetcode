class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int low=0;
        int high=nums.size()-1,ans=-1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            high=mid-1;
            else{
            if(ans==-1)
            ans=mid;
            else if(ans!=-1 && nums[ans]<=nums[mid])
            ans=mid;
            low= mid+1;
            }
        }
        return ans+1;
    }
};