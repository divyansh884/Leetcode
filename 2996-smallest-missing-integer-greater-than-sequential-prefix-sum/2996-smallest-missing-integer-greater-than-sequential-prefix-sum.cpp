class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int j=1;
        int temp=nums[0];
        while(j<n){
            if(nums[j]==nums[j-1]+1){
                temp+=nums[j];
            }
            else{
                ans=max(ans,temp);
                break;
            }
            j++;
        }
        ans=max(ans,temp);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(ans==nums[i])
            ans++;
        }
        return ans;
    }
};