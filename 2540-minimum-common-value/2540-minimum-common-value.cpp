class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for( auto it: nums1)
        mp[it]++;
        int ans=1e9+7;
        for( auto it: nums2){
            if(mp[it]!=0)
            ans=min(ans,it);
        }
        if(ans==1e9+7)
        return -1;
        return ans;
    }
};