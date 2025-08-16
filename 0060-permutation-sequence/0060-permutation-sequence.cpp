class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> vec;
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            vec.push_back(i);
        }
        while (cnt != k) {
            next_permutation(vec.begin(), vec.end());
            cnt++;
        }
        for (int i = 0; i < vec.size(); i++) {
            ans += (vec[i] + '0');
        }
        return ans;
    }
};