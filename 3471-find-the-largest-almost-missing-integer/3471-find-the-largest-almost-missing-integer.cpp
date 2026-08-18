class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
         if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=-1;
        if(k==1){
            for(auto it: mp){
                if(it.second==1)
                ans=max(ans,it.first);
            }
        }
        if(mp[nums[0]]==1)
        ans=max(ans,nums[0]);
        if(mp[nums[n-1]]==1)
        ans=max(ans,nums[n-1]);
        return ans;
    }
};