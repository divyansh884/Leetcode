class Twitter {
    unordered_map<int, vector<pair<int, int>>> tt;
    unordered_map<int, unordered_set<int>> ff;
    int time;

public:
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tt[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto t : tt[userId]) {
            pq.push(t);
            if (pq.size() > 10)
                pq.pop();
        }
        for (auto it : ff[userId]) {
            for (auto t : tt[it]) {
                pq.push(t);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        ff[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        ff[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */