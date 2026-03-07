class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int st = 0, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[st])
                st = i;
        }
        vector<int> ans(n);
        stack<int> s;
        int i = st;
        ans[i] = -1;
        s.push(nums[i]);
        i--;
        if (i < 0)
            i = n - 1;
        while (i != st) {
            while (!s.empty() && nums[i] >= s.top())
                s.pop();
            if (s.empty()) {
                ans[i] = -1;
            } else
                ans[i] = s.top();
            s.push(nums[i]);
            i--;
            if (i < 0)
                i = n - 1;
        }
        return ans;
    }
};