class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for( auto it: s){
            mp[it]++;
        }
        for( auto it: mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            int cnt=pq.top().first;
            char cc= pq.top().second;
            pq.pop();
            while(cnt!=0){
                ans+=cc;
                cnt--;
            }
        }
        return ans;
    }
};