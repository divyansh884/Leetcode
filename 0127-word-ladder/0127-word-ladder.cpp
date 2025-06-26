class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> mp;
        for (int i = 0; i < wordList.size(); i++) {
            mp[wordList[i]] = true;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string temp = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (temp == endWord) return cnt;

            for (int i = 0; i < temp.size(); i++) {
                string s = temp;
                for (char j = 'a'; j <= 'z'; j++) {
                    s[i] = j;
                    if (mp[s]) {
                        mp[s] = false;
                        q.push({s, cnt + 1});
                    }
                }
            }
        }
        return 0;
    }
};
