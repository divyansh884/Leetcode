class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int i=0,j=k-1;
        int n=nums.size();
        vector<int> ans;
        for(int ind=0;ind<k;ind++){
            pq.push({nums[ind],ind});
        }
        ans.push_back(pq.top().first);
        while(j<n-1){
            i++;
            j++;
            pq.push({nums[j],j});
            while(!pq.empty() && pq.top().second<i)
            pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};