class Solution {
public:
int solve(int index,vector<int> &nums,vector<int> &dp){
    if(index==0) return nums[index];
    if(index<0) return 0;
    if(dp[index]!=-1)return dp[index];
    int left= nums[index]+solve(index-2,nums,dp);
    int right= solve(index-1,nums,dp);
    return dp[index]=max(left,right);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int> dp(n+1,-1),dp1(n+1,-1);
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(solve(temp1.size()-1,temp1,dp1),solve(temp2.size()-1,temp2,dp));
    }
};