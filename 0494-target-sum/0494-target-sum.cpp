class Solution {
  public:
  int f(int index,int target,vector<vector<int>> &dp,vector<int> &arr,int n){
      if(index==n){
          if(target==0)
          return 1;
          return 0;
      }
      if(target<0)
      return 0;
      int take=0,ntake=0;
      if(dp[index][target]!= -1) return dp[index][target];
      take+= f(index+1,target-arr[index],dp,arr,n);
      ntake+= f(index+1,target,dp,arr,n);
      return dp[index][target]=take+ntake;
  }
    int findTargetSumWays(vector<int>& arr, int d) {
        int index=0;
        int target=0;
        for(int i=0;i<arr.size();i++){
            target+=arr[i];
        }
        if(target<d || (target-d)%2!=0)
        return 0;
        target-=d;
        target/=2;
        vector<vector<int>> dp(arr.size()+1,vector<int>(target+1,-1));
        return f(0,target,dp,arr,arr.size());
    }
};