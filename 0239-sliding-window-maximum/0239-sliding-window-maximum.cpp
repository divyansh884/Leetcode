class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<int> pq;

        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
            mp[nums[i]]++;
        }

        vector<int> ans;
        ans.push_back(pq.top());
        int i = 0, j = k;
        int n = nums.size();
        while (j < n) {
            pq.push(nums[j]);
            mp[nums[j]]++;
            mp[nums[i]]--;
            while (mp[pq.top()] == 0)
                pq.pop();

            ans.push_back(pq.top());
            i++;
            j++;
        }

        return ans;
    }
};