class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for( auto &it: mp){
            if (mp.count(it.first + 1)){
            int sum=it.second+mp[it.first+1];
            ans=max(sum,ans);
            }
        }
        return ans;
    }
};