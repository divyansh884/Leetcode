class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n=basket1.size(),mini=INT_MAX;
        long long ans=0;
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            mp[basket1[i]].first++;
            mp[basket2[i]].second++;
            mini=min(mini,min(basket1[i],basket2[i]));
        }
        vector<pair<int,int>> vec1;
        for( auto it: mp){
            int sum=it.second.first+it.second.second;
            if(sum%2!=0)
            return -1;
            else{
                int req=sum/2;
                if(it.second.first>req){
                    vec1.push_back({it.first,abs(req-it.second.first)});
                }
                else if(it.second.second>req){
                     vec1.push_back({it.first,abs(req-it.second.second)});
                }
            }
        }
        sort(vec1.begin(),vec1.end());
        int i=0,j=vec1.size()-1;
        while(i<=j){
            if(vec1[i].first<2*mini){
                ans+=vec1[i].first;
                vec1[i].second--;
                if(vec1[i].second==0)
                i++;
                vec1[j].second--;
                if(vec1[j].second==0)
                j--;
            }
            else{
                ans+=(mini*vec1[i].second);
                i++;
            }
        }
        return ans;
    }
};