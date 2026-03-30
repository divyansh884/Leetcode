class Solution {
public:
    bool checkStrings(string s1, string s2) {
        std::vector<int> odds(26);
        std::vector<int> evens(26);
        bool even = true;
        for (int i = 0; i < s1.size(); i++) {
            even = !even;
            if (even) {
                evens[s1[i] - 'a']++;
                evens[s2[i] - 'a']--;
            } else {
                odds[s1[i] - 'a']++;
                odds[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < odds.size(); i++) {
            if (odds[i] != 0 || evens[i] != 0) {
                return false;
            }
        }
        return true;
    }
};