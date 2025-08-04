class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int n = fruits.size(), ans = 1;
        int i = 0, j = 0, curr = fruits[0];
        while (j < n) {
            if (mp.size() == 2) {
                if (mp.find(fruits[j]) == mp.end()) {
                    i = mp[fruits[j - 1]];
                    mp.clear();
                    mp[fruits[j - 1]] = i;
                    mp[fruits[j]] = j;
                    curr = fruits[j];
                } else {
                    if (fruits[j] != curr) {
                        mp[fruits[j]] = j;
                        curr = fruits[j];
                    }
                }
            } else {
                if (mp.find(fruits[j]) == mp.end()) {
                    mp[fruits[j]] = j;
                    curr = fruits[j];
                } else {
                    if (fruits[j] != curr) {
                        mp[fruits[j]] = j;
                        curr = fruits[j];
                    }
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};