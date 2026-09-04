class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            int mini=1e9;
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
            }
            if(maxi-mini<=k)
            return i;
        }
        return -1;
    }
};