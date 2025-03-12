class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n= nums.size();
        int high=n-1;
        int low =0;
        int ans=INT_MIN, ans1=INT_MAX;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(nums[mid]<0){
                if(mid>ans)
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(ans==INT_MIN)
        ans=-1;
        high=n-1;
        low =0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(nums[mid]>0){
                if(mid<ans1)
                ans1=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return max(ans+1,n-1-ans1+1);
    }
};