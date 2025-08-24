class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0;
        int ans = 0;
        while (j < n) {
            if (nums[j] == 1) {
                j++;
            } 
            else if(nums[j]==0){
            cnt++;
            j++;
            }
            while(cnt>1){
                if(nums[i]==0)cnt--;
                i++;
            }
            ans=max(ans,j-i-1);
        }
        ans = max(ans, j - i-1);
        return ans;
    }
};