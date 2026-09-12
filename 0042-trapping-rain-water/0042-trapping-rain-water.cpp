class Solution {
public:
    vector<int> nge(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> ngs(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int trap(vector<int>& height) {
        vector<int> ng = nge(height);
        vector<int> ns = ngs(height);
        int ans = 0;
        int n=height.size();
        for (int i = 0; i < n; i++) {
            if (ng[i] == -1 || ns[i] == -1)
                continue;
            ans += (min(height[ng[i]], height[ns[i]]) - height[i]) *
                   (ng[i] - ns[i]-1);
        }
        return ans;
    }
};