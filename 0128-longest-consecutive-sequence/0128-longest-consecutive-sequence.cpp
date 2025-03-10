class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int ans= INT_MIN;
        if(nums.size()<=1)
        return nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1)
            count++;
            else if(nums[i+1]-nums[i]>1){
                ans= max(ans,count);
                count=0;
            }
        }
        ans= max(ans,count);
        return ans+1;
    }
};