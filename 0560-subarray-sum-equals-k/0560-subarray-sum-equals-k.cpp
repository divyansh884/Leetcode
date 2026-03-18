class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n);
        for(int i=0;i<n;i++){
            prefix[i]= nums[i];
            if(i>0)
            prefix[i]+=prefix[i-1];
        }
        unordered_map<int,int> mp;
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mp.find(prefix[i]-k)!=mp.end())
            cnt+=mp[prefix[i]-k];
            mp[prefix[i]]++;
        }
        return cnt;
    }
};