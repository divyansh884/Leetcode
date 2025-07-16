class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int cnteven = 0, cntodd = 0;
        for (auto it : nums) {
            if (it % 2 == 0)
                cnteven++;
            else
                cntodd++;
        }
        int comp = 0;
        int check=nums[0];
        for (int i=1;i<n;i++) {
            if(nums[i]%2!=check%2){
                comp++;
                check=nums[i];
            }
        }
        return max(comp+1, max(cnteven, cntodd));
    }
};
