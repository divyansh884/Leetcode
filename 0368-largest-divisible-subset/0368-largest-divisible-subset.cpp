class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(),1), hash(nums.size());
       int maxi=1;
       int lastind=0;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxi){
                maxi=dp[i];
                lastind=i;
            }
       }
        vector<int> ans;
        ans.push_back(nums[lastind]);
        while(hash[lastind]!=lastind){
            lastind= hash[lastind];
            ans.push_back(nums[lastind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};