class Solution {
public:
    vector<int> solve(vector<int>& boards, int mid, int k) {
        int temp = 1;
        int sum = 0;
        int maxi = INT_MIN;
        for (auto it : boards) {
            if (sum + it <= mid) {
                sum += it;
            } else {
                if (it > mid)
                    return {k+1,maxi};
                maxi=max(maxi,sum);
                temp++;
                sum = it;
            }
        }
        maxi=max(maxi,sum);
        return {temp,maxi};
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0, ans = -1;
        int high = accumulate(nums.begin(), nums.end(),0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<int> temp = solve(nums, mid, k);
            if (temp[0] <= k) {
                ans = temp[1];
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};