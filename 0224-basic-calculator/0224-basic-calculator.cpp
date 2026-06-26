class Solution {
public:
    int calculate(string s) {
        stack<long long> stn;
        stack<char> stc;
        int n = s.size();
        long long  num = 0;
        bool hasNum = false;
        auto eval = [&]() {
            long long b = stn.top();
            stn.pop();
            long long a = stn.top();
            stn.pop();
            char op = stc.top();
            stc.pop();
            if (op == '+')
                stn.push(a + b);
            else
                stn.push(a - b);
        };
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ')
                continue;
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                hasNum = true;
            } else {
                if (hasNum) {
                    stn.push(num);
                    num = 0;
                    hasNum = false;
                }
                if (s[i] == '(') {
                    stc.push('(');
                } else if (s[i] == '+' || s[i] == '-') {
                    int j = i - 1;
                    while (j >= 0 && s[j] == ' ')
                        j--;

                    if (s[i] == '-' && (j < 0 || s[j] == '('))
                        stn.push(0);

                    while (!stc.empty() && stc.top() != '(')
                        eval();

                    stc.push(s[i]);
                } else if (s[i] == ')') {

                    while (!stc.empty() && stc.top() != '(')
                        eval();

                    stc.pop();
                }
            }
        }
        if (hasNum)
            stn.push(num);
        while (!stc.empty())
            eval();
        return stn.top();
    }
};