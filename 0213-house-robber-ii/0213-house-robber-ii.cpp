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
        if(n==1)
        return nums[0];
        vector<int> dp(n,-1);
        int l =f(index,n-1,dp,nums);
        vector<int> dp1(n,-1);
        int r =f(index+1,n,dp1,nums);
        return max(l,r);
    }
};