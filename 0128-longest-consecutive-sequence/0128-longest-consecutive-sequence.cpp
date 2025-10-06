class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        int ans=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                if(nums[i+1]-nums[i]==1)
                cnt++;
                else{
                    ans=max(ans,cnt);
                    cnt=1;
                }
            }
        }
        ans=max(cnt,ans);
        return ans;
    }
};