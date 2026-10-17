class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currj=0;
        int far=0;
        int step=0;
        for (int i = 0; i < n-1; i++) {
            int jump=i+nums[i];
            far=max(far,jump);
            if(i>=currj){
                step++;
                currj=far;
            }
        }
        return step;
    }
};