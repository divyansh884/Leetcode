class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            m[word[i]]++;
        }
        int count = 0;
        for(char c='a';c<='z';c++){
            if (m[c] >= 1 && m[toupper(c)] >= 1) {
                count++;
            }
        }
        return count;
    }
};