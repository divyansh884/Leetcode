class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int jump=nums[i];
            if(i<=maxr){
                maxr=max(maxr,i+jump);
            }
        }
        if(maxr>=n-1)
        return true;
        return false;
    }
};