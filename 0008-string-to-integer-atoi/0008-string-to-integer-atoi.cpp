class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        bool numcheck = false;
        int sign = 1;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == '-' || s[i] == '+') && !numcheck) {
                numcheck = true;

                if (s[i] == '-')
                    sign = -1;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                int digit = s[i] - '0';
                if (ans > INT_MAX / 10 ||
                    (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                ans = ans * 10 + digit;
                numcheck = true;
            }
            else {
                if (s[i] >= 'a' && s[i] <= 'z')
                    break;
                if (numcheck)
                    break;
            }
        }
        return ans * sign;
    }
};