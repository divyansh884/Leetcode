class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;
        priority_queue<int> pq;
        priority_queue<int,vector<int>,greater<int>> pq1;
        vector<long long> prefix,suffix;
        long long sum=0;
        for(int i=0;i<2*n;i++){
            if(pq.size()<n){
                sum+=nums[i];
                pq.push(nums[i]);
                if(pq.size()==n)
                prefix.push_back(sum);
            }
            else if(pq.size()==n){
                if(nums[i]<pq.top()){
                    sum-=pq.top();
                    sum+=nums[i];
                    pq.pop();
                    pq.push(nums[i]);
                }
               prefix.push_back(sum);
            }
        }
        sum=0;
        for(int i=nums.size()-1;i>n-1;i--){
            if(pq1.size()<n){
                sum+=nums[i];
                pq1.push(nums[i]);
                if(pq1.size()==n)
                suffix.push_back(sum);
            }
            else if(pq1.size()==n){
                if(nums[i]>pq1.top()){
                    sum-=pq1.top();
                    sum+=nums[i];
                    pq1.pop();
                    pq1.push(nums[i]);
                }
                suffix.push_back(sum);
            }
        }
        reverse(suffix.begin(),suffix.end());
        long long ans=LLONG_MAX;
        for(int i=0;i<prefix.size();i++){
            ans=min(ans,prefix[i]-suffix[i]);
        }
        return ans;
    }
};