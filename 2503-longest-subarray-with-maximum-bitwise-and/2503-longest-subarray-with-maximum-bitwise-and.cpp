class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = -1, n = nums.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        int cnt=0,ans=1;
        for(int i=0;i<n;i++){
            if(maxi==nums[i])
            cnt++;
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};