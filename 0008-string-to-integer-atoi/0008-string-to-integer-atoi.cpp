class Solution {
public:
    int myAtoi(string s) {
        long long int n = s.size();
        long long int re = 0;
        vector<long long int> ans;
        bool check = false;
        bool checkne = false;
        long long int st = 0;
        while (s[st] == ' ') {
            st++;
        }
        if (s[st] == '-' || s[st] == '+') {
            check = true;
            if (s[st] == '-')
                checkne = true;
        }
        for (long long int i = check ? st + 1 : st; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans.push_back(s[i] - '0');
            } else {
                break;
            }
        }
        for (long long int j = 0; j < ans.size(); j++) {
            if (re > INT_MAX && checkne)
                return INT_MIN;
            else if (re > INT_MAX && checkne == false)
                return INT_MAX;
            re = re * 10 + (ans[j]);
        }
        if (re > INT_MAX && checkne)
            return INT_MIN;
        else if (re > INT_MAX && checkne == false)
            return INT_MAX;
        if (checkne)
            re *= -1;
        return re;
    }
};