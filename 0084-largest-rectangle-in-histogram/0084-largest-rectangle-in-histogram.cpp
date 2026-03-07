class Solution {
public:
    vector<int> ns(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> ps(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pr = ps(heights);
        vector<int> nr = ns(heights);
        int n = heights.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int b = nr[i] - pr[i] - 1;
            int aa = h * b;
            ans = max(ans, aa);
        }
        return ans;
    }
};