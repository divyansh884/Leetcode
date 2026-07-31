class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vec(26, 0);
        for (auto it : word)
            vec[it - 'a']++;
        sort(vec.rbegin(),vec.rend());
        int cnt = 1;
        int step = 2;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if(vec[i]==0)
            break;
            ans += vec[i]*cnt;
            step++;
            if (step == 10) {
                cnt++;
                step = 2;
            }
        }
        return ans;
    }
};