class Solution {
public:
int f(int index,int n,vector<int> &dp,vector<int> &nums){
    if(index>=n)
    return 0;
    if(dp[index]!=-1) return dp[index];
    int take= nums[index]+ f(index+2,n,dp,nums);
    int ntake= f(index+1,n,dp,nums);
    return dp[index]=max(take,ntake);
}
    int rob(vector<int>& nums) {
        int index=0,n=nums.size();
        vector<int> dp(n,-1);
        return f(index,n,dp,nums);
    }
};