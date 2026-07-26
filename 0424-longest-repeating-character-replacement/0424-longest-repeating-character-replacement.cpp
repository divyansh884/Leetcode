class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 1;
        for (char cc = 'A'; cc <= 'Z'; cc++) {
            queue<int> pq;
            int l = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != cc) {
                    if (k == 0) {
                        l = i + 1;
                    } else if (pq.size() < k) {
                        pq.push(i);
                    } else {
                        l = pq.front() + 1;
                        pq.pop();
                        pq.push(i);
                    }
                }
                ans = max(ans, i - l + 1);
            }
        }
        return ans;
    }
};