class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
       int low=-1,n=nums.size();
       int high=0,ans=-1;
       for(int i=0;i<n;i++){
        low= max(low,nums[i]);
        high+=nums[i];
       }
       while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=1;
        int we=0;
        for(int i=0;i<n;i++){
            if(we+nums[i]>mid){
                we=nums[i];
                cnt++;
            }
            else
            we+=nums[i];
        }
        if(cnt<=k){
            ans=mid;
            high=mid-1;
        }
        else if(cnt>k)
        low=mid+1;
       }
       return ans;
    }
};