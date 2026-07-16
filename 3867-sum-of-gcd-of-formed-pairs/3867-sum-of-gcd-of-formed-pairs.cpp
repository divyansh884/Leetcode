class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans = 0;
        int n=nums.size();
        int mex = nums[0];
        vector<int> gg(n);
        gg[0] = mex;
        for (int i = 1; i < n; i++) {
            mex = max(mex, nums[i]);
            gg[i] = gcd(nums[i], mex);
        }
        sort(gg.begin(), gg.end());
        int i = 0;
        int j = gg.size() - 1;
        while (i < j) {
            int temp = gcd(gg[i], gg[j]);
            ans += (1LL * temp);
            i++;
            j--;
        }
        return ans;
    }
};