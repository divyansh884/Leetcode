class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordLen = words[0].size();
        int cnt = words.size();
        int totalLen = wordLen * cnt;

        if ((int)s.size() < totalLen) return ans;

        unordered_map<string, int> need;
        for (auto &w : words) need[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, matched = 0;
            unordered_map<string, int> have;

            for (int right = offset; right + wordLen <= (int)s.size(); right += wordLen) {
                string w = s.substr(right, wordLen);

                if (need.find(w) == need.end()) {
                    have.clear();
                    matched = 0;
                    left = right + wordLen;
                    continue;
                }

                have[w]++;
                matched++;

                while (have[w] > need[w]) {
                    string rem = s.substr(left, wordLen);
                    have[rem]--;
                    matched--;
                    left += wordLen;
                }

                if (matched == cnt) {
                    ans.push_back(left);

                    string rem = s.substr(left, wordLen);
                    have[rem]--;
                    matched--;
                    left += wordLen;
                }
            }
        }

        return ans;
    }
};
