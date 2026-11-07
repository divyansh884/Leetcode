class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqs;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pqt;

        int n = servers.size();
        int m = tasks.size();

        for (int i = 0; i < n; i++) {
            pqs.push({servers[i], i});
        }

        vector<int> ans(m);
        long long current_time=0;
        for (int i = 0; i < m; i++) {
            current_time = max(current_time, (long long)i);
            while (!pqt.empty() && pqt.top().first <= i) {
                int idx = pqt.top().second;
                pqt.pop();
                pqs.push({servers[idx], idx});
            }

            if (pqs.empty()) {
               current_time = pqt.top().first;
                while (!pqt.empty() && pqt.top().first <= current_time) {
                    int idx = pqt.top().second;
                    pqt.pop();
                    pqs.push({servers[idx], idx});
                }

                auto it = pqs.top();
                pqs.pop();

                ans[i] = it.second;
                pqt.push({current_time + tasks[i], it.second});
            } 
            else {
                auto it = pqs.top();
                pqs.pop();

                ans[i] = it.second;
                pqt.push({current_time + tasks[i], it.second});
            }
        }
        return ans;
    }
};