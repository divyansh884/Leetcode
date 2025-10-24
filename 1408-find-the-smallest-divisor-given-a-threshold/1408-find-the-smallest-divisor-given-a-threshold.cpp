class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=0;
        for( int i=0;i<n;i++){
            high=max(high,nums[i]);
        }
        int ans=high;
        while(low<=high){
            int mid= low+(high-low)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                int add= (nums[i]+mid-1)/mid;
                sum+=add;
            }
            if(sum<=threshold){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};