class Solution {
public:
    int f(int i, int j, vector<int>& nums1, vector<int>& nums2,
          vector<vector<vector<int>>>& dp, int check) {
        if (i >= nums1.size() || j >= nums2.size()) {
            if (check)
                return 0;
            return -1000001;
        }
         if(dp[i][j][check]!=-1) return dp[i][j][check];
        int take =
            nums1[i] * nums2[j] + f(i + 1, j + 1, nums1, nums2, dp, 1);
        int ntake = max(f(i + 1, j, nums1, nums2, dp, check),
                        f(i, j + 1, nums1, nums2, dp, check));
        return dp[i][j][check]=max(take, ntake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<vector<int>>> dp(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(2,-1)));
        return f(0, 0, nums1, nums2, dp, 0);
    }
};