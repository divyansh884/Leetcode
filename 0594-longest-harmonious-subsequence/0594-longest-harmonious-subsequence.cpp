class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        int i=0,ans=0;
        while(i<n){
            if(mp[nums[i]+1]!=0){
                int sum=mp[nums[i]]+mp[nums[i]+1];
                ans=max(ans,sum);
            }
            i+=mp[nums[i]];
        }
        return ans;
    }
};