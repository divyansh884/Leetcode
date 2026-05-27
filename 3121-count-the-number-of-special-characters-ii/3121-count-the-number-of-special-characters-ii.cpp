class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26, -1), up(26, -1);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z')
                low[word[i] - 'a'] = i;
            else {
                if(up[word[i] - 'A']==-1)
                up[word[i] - 'A'] = i;
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (low[i] < up[i] && low[i] != -1)
                cnt++;
        }
        return cnt;
    }
};