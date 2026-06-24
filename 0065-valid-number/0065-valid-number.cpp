class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        if (n == 1) {
            if (s[0] >= '0' && s[0] <= '9')
                return true;
            return false;
        }
        if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))
            return false;
        int exp = -1;
        int dot = -1;
        if (s[0] == '.')
            dot = 0;
        for (int i = 1; i < n; i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                if ((s[i] != 'e' && s[i] != 'E') || exp != -1)
                    return false;
                else if ((s[i - 1] >= '0' && s[i - 1] <= '9')) {
                    exp = i;
                } else if (s[i - 1] == '.') {
                    if (i - 2 >= 0 && s[i - 2] >= '0' && s[i - 2] <= '9') {
                        exp = i;
                        continue;
                    } else
                        return false;
                } else
                    return false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i - 1 != exp || i == n - 1)
                    return false;
            } else if (s[i] == '.') {
                if (exp != -1 || dot != -1)
                    return false;
                else {
                    dot = i;
                }
            } else
                continue;
        }
        if (exp == n - 1)
            return false;
        if(dot==n-1 && (s[dot-1]=='+' || s[dot-1]=='-'))
            return false;
        return true;
    }
};