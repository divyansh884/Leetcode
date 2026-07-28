class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> mp(26, 0);

        for (char c : s)
            mp[c - 'a']++;

        int i = n / 2;
        int j = n / 2;
        if (n % 2 == 0)
            j--;
        for (int ind = 0; ind < 26; ind++) {
            if (mp[ind] % 2) {
                s[n / 2] = ind + 'a';
                mp[ind]--;
                i++;
                j--;
                break;
            }
        }
        for (int ind = 25; ind >= 0; ind--) {
            while (mp[ind] > 0) {
                s[i] = ind + 'a';
                s[j] = ind + 'a';
                mp[ind] -= 2;
                i++;
                j--;
            }
        }

        return s;
    }
};