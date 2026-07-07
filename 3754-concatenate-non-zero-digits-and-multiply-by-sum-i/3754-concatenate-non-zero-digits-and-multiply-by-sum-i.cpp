class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> ans;
        long long sum = 0;
        long long x = 0;
        while (n != 0) {
            int add = n % 10;
            sum += add;
            if (add != 0)
                ans.push_back(add);
            n /= 10;
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            x=x*10+ans[i];
        }
        return sum*x;
    }
};