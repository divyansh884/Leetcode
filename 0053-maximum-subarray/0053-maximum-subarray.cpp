class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,n=nums.size();
        int maxsum=nums[0];
        int i=0,j=0;
        while(j<n){
            sum+=nums[j];
            maxsum=max(maxsum,sum);
            while(sum<0 && i<=j){
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return maxsum;
    }
};