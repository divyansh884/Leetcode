class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=1;
        for(auto it: mp){
            if(it.second<=1|| it.first==1)
            continue;
            int cnt=0;
            long long st=it.first;
            while(mp.find(st)!=mp.end()){
                if(mp[st]>1)
                cnt++;
                else{
                    cnt++;
                    break;
                }
                st*=st;
                if(st>=1e9+7)
                break;
            }
            ans=max(ans,cnt*2-1);
        }
        if(mp[1]%2==0)
        return max(ans,mp[1]-1);
        return max(ans,mp[1]);
    }
};