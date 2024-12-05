class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,bool> mp;
        unordered_map<int,int> nms;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=true;
            nms[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(nms[nums[i]]==1 && mp[nums[i]-1]!=true &&mp[nums[i]+1]!=true)
            ans.push_back(nums[i]);
        }
        return ans;
    }
};