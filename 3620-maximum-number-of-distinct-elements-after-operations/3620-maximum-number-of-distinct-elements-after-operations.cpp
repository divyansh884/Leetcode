class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mp;
        int prev=-1e9-7;
        for(int i=0;i<n-1;i++){
            mp[nums[i]]++;
            if(nums[i]!=nums[i+1]){
                int st=max(prev,nums[i]-k);
                int end =nums[i]+k;
                ans+= min(mp[nums[i]],end-st+1);
                prev=st+min(mp[nums[i]],end-st+1);
            }
        }
        mp[nums[n-1]]++;
        int st=max(prev,nums[n-1]-k);
        int end=nums[n-1]+k;
        ans+= min(mp[nums[n-1]],end-st+1);
        return ans;
    }
};