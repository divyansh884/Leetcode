class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        long long sum = mass;
        for (int i = 0; i < n; i++) {
            if (sum < a[i])
                return false;
            sum += a[i];
        }
        return true;
    }
};