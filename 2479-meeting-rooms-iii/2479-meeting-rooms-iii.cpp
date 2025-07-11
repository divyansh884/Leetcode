class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        unordered_map<long long, long long> mp;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        priority_queue<long long, vector<long long>, greater<long long>> room;

        for (long long i = 1; i <= n; i++) {
            room.push(i);
        }

        long long i = 0;
        while (i < meetings.size()) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];

            if (pq.empty()) {
                pq.push({end, room.top()});
                mp[room.top()]++;
                room.pop();
                i++;
            } else {
                while (!pq.empty() && pq.top().first <= start) {
                    room.push(pq.top().second);
                    pq.pop();
                }
                if (!room.empty()) {
                    long long temp = room.top();
                    pq.push({end, temp});
                    mp[temp]++;
                    room.pop();
                    i++;
                } else {
                    long long duration = end - start;
                    long long newStart = pq.top().first;
                    long long newEnd = newStart + duration;
                    long long roomNum = pq.top().second;
                    pq.pop();
                    pq.push({newEnd, roomNum});
                    mp[roomNum]++;
                    i++;
                }
            }
        }

         long long ans = 0, maxi = 0;
        for (long long i = n; i > 0; i--) {
            if (mp[i] >= maxi) {
                ans = i - 1;
                maxi = mp[i];
            }
        }
        return (int)ans;
    }
};
