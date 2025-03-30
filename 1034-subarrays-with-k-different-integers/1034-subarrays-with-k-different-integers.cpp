class Solution {
public:
int atmost(vector<int>& nums, int k){
    int ans=0,i=0,j=0,n=nums.size();
    unordered_map<int,int> mp;
    while(j<n){
        mp[nums[j]]++;
        while(mp.size()>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};