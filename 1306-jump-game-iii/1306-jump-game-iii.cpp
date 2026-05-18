class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<int> vis(n + 1, 0);
        q.push(start);
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            vis[index] = 1;
            if (arr[index] == 0)
                return true;
            if (index + arr[index] < n && !vis[index + arr[index]])
                q.push(index + arr[index]);
            if (index - arr[index] >= 0 && !vis[index - arr[index]])
                q.push(index - arr[index]);
        }
        return false;
    }
};