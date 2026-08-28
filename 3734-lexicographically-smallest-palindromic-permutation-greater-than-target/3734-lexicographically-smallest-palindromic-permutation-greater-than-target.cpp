class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        
        int cnto = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (mp[c] % 2 != 0)
                cnto++;
        }
        
        if (cnto > 1)
            return "";
        if (cnto == 1 && n % 2 == 0)
            return "";
            
        string ans = "";
        int half = (n - 1) / 2;
        
        for (int i = 0; i <= half + 1; i++) {
            string temp(n, ' ');
            unordered_map<char, int> mp1 = mp;
            bool possible = true;
            
            for (int j = 0; j < i; j++) {
                char cc = target[j];
                int required = (j != n - 1 - j) ? 2 : 1;
                
                if (mp1[cc] >= required) {
                    temp[j] = cc;
                    temp[n - 1 - j] = cc;
                    mp1[cc] -= required;
                } else {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) continue;
            
            if (i <= half) {
                bool check = false;
                char st = target[i] + 1;
                int required = (i != n - 1 - i) ? 2 : 1;
                
                for (char cc = st; cc <= 'z'; cc++) {
                    if (mp1[cc] >= required) {
                        temp[i] = cc;
                        temp[n - 1 - i] = cc;
                        mp1[cc] -= required;
                        check = true;
                        break;
                    }
                }
                
                if (!check) continue;
            }
            
            for (int ind = i + 1; ind <= half; ind++) {
                int required = (ind != n - 1 - ind) ? 2 : 1;
                for (char cc = 'a'; cc <= 'z'; cc++) {
                    if (mp1[cc] >= required) {
                        temp[ind] = cc;
                        temp[n - 1 - ind] = cc;
                        mp1[cc] -= required;
                        break; 
                    }
                }
            }
            
            if (temp > target) {
                if (ans == "") {
                    ans = temp;
                } else if (temp < ans) {
                    ans = temp;
                }
            }
        }
        
        return ans;
    }
};