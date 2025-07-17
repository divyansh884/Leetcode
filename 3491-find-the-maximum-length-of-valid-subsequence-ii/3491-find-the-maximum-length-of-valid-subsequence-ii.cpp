class Solution {
public:
int dp[1001][1001];
int arnold(vector<int>& nums, int i , int rem, int k){
    if(dp[i][rem]!=-1) return dp[i][rem];
    int n = nums.size() ;
    int x=1 ; 
    for(int j =i+1 ; j<n ; j++){
        if((nums[i]+nums[j])%k==rem){
             x += arnold(nums , j , rem , k);
            break ; 
        }
    }
    return dp[i][rem]= x ; 
}
    int maximumLength(vector<int>& nums, int k) {
        memset(dp , -1 , sizeof(dp));
        int n = nums.size();
        int res =1 ; 
        for(int i =0; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                res = max(res , arnold(nums , j , (nums[i]+nums[j])%k , k ));
            }
        }
        return res+1; 
    }
};