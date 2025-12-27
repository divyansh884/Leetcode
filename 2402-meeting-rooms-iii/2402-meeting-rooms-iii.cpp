class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        map<int,long long> mp;
        priority_queue<int,vector<int>,greater<int>> room;
        for(int i=0;i<n;i++)
        room.push(i);
        for(int i=0;i<meetings.size();i++){
            while(!pq.empty()){
                if(meetings[i][0]>=pq.top().first){
                    long long tp=pq.top().second;
                    pq.pop();
                    room.push(tp);
                }
                else
                break;
            }
            if(!room.empty()){
                int to=room.top();
                room.pop();
                mp[to]++;
                pq.push({meetings[i][1],to});
            }
            else{
                int roo=pq.top().second;
                long long time=pq.top().first;
                pq.pop();
                mp[roo]++;
                pq.push({time+(meetings[i][1]-meetings[i][0]),roo});
            }
        }
        int ans=0,cnt=0;
        for(auto it: mp){
            if(it.second>cnt){
                ans=it.first;
                cnt=it.second;
            }
        }
        return ans;
    }
};