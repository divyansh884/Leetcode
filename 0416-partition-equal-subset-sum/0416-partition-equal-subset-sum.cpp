class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int index=0,n=nums.size(),sum=0,total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total%2!=0)
        return false;
        sort(nums.begin(),nums.end());
        vector<vector<bool>> dp(n, vector<bool>((total/2) + 1, false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if (nums[0] <= (total/2))dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=total/2;j++){
                bool take=false;
                if(nums[i]<=j) take= dp[i-1][j-nums[i]];
                bool ntake=dp[i-1][j];
                dp[i][j]=take||ntake;
            }
        }
        return dp[n-1][total/2];
        }
};