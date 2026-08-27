class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string ans = "";
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        int break_idx = n; 
        
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (char c = target[i]; c <= 'z'; c++) {
                if (mp[c] > 0) {
                    ans.push_back(c);
                    mp[c]--;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                break_idx = i;
                break;
            }
            
            if (!ans.empty() && target[i] < ans.back())
                break;
        }
        
        for (char c = 'a'; c <= 'z'; c++) {
            while (mp[c] > 0) {
                ans.push_back(c);
                mp[c]--;
            }
        }
        
        if (ans <= target) {
            int start = min(n - 1, break_idx);
            
            for (int i = start; i >= 0; i--) {
                bool check = false;
                char cc = ans[i];
                int ind = -1;
                for (int j = i + 1; j < n; j++) {
                    if (cc < ans[j] && ans[j] > target[i]) {
                        if (ind != -1 && ans[j] < ans[ind]) {
                            ind = j;
                        }
                        else if (ind == -1)
                            ind = j;
                        check = true;
                    }
                }
                if (check) {
                    swap(ans[i], ans[ind]);
                    sort(ans.begin() + i + 1, ans.end());
                    break;
                }
            }
            if (ans <= target)
                return "";
        }

        return ans;
    }
};