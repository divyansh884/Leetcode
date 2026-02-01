class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost= nums[0],n=nums.size();
        int min1=1e9,min2=1e9;
        sort(nums.begin()+1,nums.end());
        return cost+nums[1]+nums[2];
    }
};