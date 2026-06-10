class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=0;
        int mini=1e9+7;
        for(auto it: nums){
            maxi=max(maxi,it);
            mini=min(mini,it);
        }
        long long ans=maxi-mini;
        return ans*k;
    }
};