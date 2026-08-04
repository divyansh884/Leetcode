class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN,mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(mp[i]==0)
            ans.push_back(i);
        }
        return ans;
    }
};