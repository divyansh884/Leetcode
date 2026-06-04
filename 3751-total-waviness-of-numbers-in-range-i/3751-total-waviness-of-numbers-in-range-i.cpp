class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        int st = max(num1, 100);
        if (num2 < st)
            return ans;
        for (int i = st; i <= num2; i++) {
            string s = to_string(i);
            for (int j = 1; j < s.size() - 1; j++) {
                if (s[j] > s[j + 1] && s[j] > s[j - 1])
                    ans++;
                else if (s[j] < s[j + 1] && s[j] < s[j - 1])
                    ans++;
            }
        }
        return ans;
    }
};