class Solution {
public:
    bool isRotatedSorted(vector<int>& a) {
        int k = a.size();
        int cnt = 0;

        for (int i = 0; i < k; i++) {
            if (a[i] > a[(i + 1) % k])
                cnt++;
        }

        return cnt <= 1;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool ok = true;

            for (int i = 0; i < n; i += k) {
                vector<int> block(nums.begin() + i, nums.begin() + i + k);
                vector<int> sorted_block(sorted_nums.begin() + i,
                                         sorted_nums.begin() + i + k);
                vector<int> ss = block;
                sort(ss.begin(),ss.end());
                if (ss!= sorted_block || !isRotatedSorted(block)) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans += k;
        }
        return ans;
    }
};