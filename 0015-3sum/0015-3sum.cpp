class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       set<vector<int>> ans;
       vector<vector<int>> ans1;
       int n=nums.size();
       sort(nums.begin(),nums.end());
       map<int,int> mp;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mp.find(0-(nums[i]+nums[j]))!=mp.end())
            ans.insert({nums[mp[0-(nums[i]+nums[j])]],nums[i],nums[j]});
        }
        mp[nums[i]]=i;
       } 
       for(auto it: ans){
        ans1.push_back(it);
       }
       return ans1;
    }
};