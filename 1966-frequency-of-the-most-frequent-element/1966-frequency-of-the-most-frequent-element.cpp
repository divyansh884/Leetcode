class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int ans=INT_MIN;
        unordered_map<long long int,long long int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        vector<pair<long long int,long long int>> num;
        for(auto i:mp){
            num.push_back(make_pair(i.first,i.second));
        }
        sort(num.begin(),num.end());
        for(long long int i=0;i<num.size();i++){
            long long int count=num[i].second;
            long long int ch=k;
            for(long long int j=i-1;j>=0;j--){
                long long int add=(num[i].first-num[j].first)*num[j].second;
                if(ch>=add){
                    ch-=add;
                    count+=num[j].second;
                }
                else{
                    long long int ad=num[i].first-num[j].first;
                    long long int s= ch/ad;
                    ans=max(count+s,ans);
                    break;
                }
            }
            ans=max(count,ans);
        }
        return int(ans);
    }
};