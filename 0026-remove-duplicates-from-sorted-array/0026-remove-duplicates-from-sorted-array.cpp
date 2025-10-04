class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        nums.clear();
        for(auto it: mp){
            nums.push_back(it.first);
        }
        sort(nums.begin(),nums.end());
        return mp.size();
    }
};