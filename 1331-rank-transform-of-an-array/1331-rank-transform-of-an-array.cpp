class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> nums;
        vector<int> ans(n);
        if(n==0)
        return ans;
        for (int i = 0; i < n; i++) {
            nums.push_back({arr[i], i});
        }
        sort(nums.begin(), nums.end());
        int cnt=1;
        ans[nums[0].second]=cnt;
        for (int i = 1; i < n; i++) {
            if(nums[i].first!=nums[i-1].first)
            cnt++;
            ans[nums[i].second]=cnt;
        }
        return ans;
    }
};