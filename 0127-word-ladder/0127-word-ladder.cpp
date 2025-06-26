class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    temp[i] = ch;
                    if (wordSet.find(temp) != wordSet.end()) {
                        q.push({temp, steps + 1});
                        wordSet.erase(temp);  // avoid revisiting
                    }
                }
            }
        }

        return 0;
    }
};
