class Solution {
public:
int f(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int i = 0, j = 0;
        int cntodd=0 , ans = 0;
        while (j < nums.size()) {
            if(nums[j]%2==1)
            cntodd++;
            while (cntodd > goal) {
                if(nums[i]%2==1)
                cntodd--;
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};