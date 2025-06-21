class Solution {
    public:
       vector<int> nextsamller(vector<int> heights, int n) {
        stack<int> sl;
         sl.push(-1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            while (sl.top() !=-1 && heights[sl.top()] >= curr) {
                sl.pop();
            }
            ans[i] = sl.top();
            sl.push(i);
        }
        return ans;
    }
    vector<int> prevsamller(vector<int> heights, int n) {
        stack<int> sl;
        sl.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (sl.top() != -1 && heights[sl.top()] >= curr) {
                sl.pop();
            }
            ans[i] = sl.top();
            sl.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = nextsamller(heights, n);
        vector<int> prev(n);
        prev = prevsamller(heights, n);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newans = l * b;
            ans = max(newans, ans);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=-1e9;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int see=largestRectangleArea(heights);
            maxi=max(see,maxi);
        }
        return maxi;
    }
};