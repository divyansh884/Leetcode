class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
            count++;
            else{
                ans=max(count,ans);
                count=0;
            }
        }
        ans=max(count,ans);
        return ans;
    }
};