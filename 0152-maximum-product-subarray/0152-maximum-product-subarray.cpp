class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int ans= INT_MIN;
        int pref=1,sef=1;
        for(int i=0;i<n;i++){
            if( pref==0)pref=1;
            if( sef==0)sef=1;
            pref*=nums[i];
            sef*=nums[n-1-i];
            ans= max(ans,max(pref,sef));
        }
        return ans;
    }
};