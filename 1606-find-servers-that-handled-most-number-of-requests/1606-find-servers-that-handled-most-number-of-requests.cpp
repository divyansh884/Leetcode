class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        set<int> st;
        for (int i = 0; i < k; i++) {
            st.insert(i);
        }

        unordered_map<int, int> mp;
        int cnt = 0;
        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            int time = arrival[i];

            while (!pq.empty() && pq.top().first <= time) {
                st.insert(pq.top().second);
                pq.pop();
            }

            if (st.empty())
                continue;

            int server = i % k;
            auto it = st.lower_bound(server);

            if (it == st.end()) {
                it = st.begin();
            }

            int x = *it;

            pq.push({time + load[i], x});
            mp[x]++;
            cnt = max(cnt, mp[x]);

            st.erase(it);
        }

        vector<int> ans;

        for (auto it : mp) {
            if (it.second == cnt)
                ans.push_back(it.first);
        }

        return ans;
    }
};