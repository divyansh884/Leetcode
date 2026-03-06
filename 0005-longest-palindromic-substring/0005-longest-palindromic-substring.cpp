class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++){

            // EVEN length palindrome
            int st = i, ed = i + 1;
            while(st >= 0 && ed < n && s[st] == s[ed]){
                st--;
                ed++;
            }

            if(ans.size() < ed - st - 1)
                ans = s.substr(st + 1, ed - st - 1);

            // ODD length palindrome
            st = i;
            ed = i;
            while(st >= 0 && ed < n && s[st] == s[ed]){
                st--;
                ed++;
            }

            if(ans.size() < ed - st - 1)
                ans = s.substr(st + 1, ed - st - 1);
        }

        return ans;
    }
};