class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,n=nums.size();
        int i=0,j=0;
        int ans=INT_MAX;
        while(j<n && i<n){
            sum+=nums[j];
            while(sum>=target){
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
            if(i>j)
            j=i;
        }
        if(ans==INT_MAX)
        return 0;
        return ans;
    }
};