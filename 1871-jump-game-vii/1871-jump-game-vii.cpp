class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> check;
        check.push_back(0);
        for (int i = 1; i < n; i++) {
            if (s[i] == '1')
                continue;
            int low = 0, high = check.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (check[mid] + maxJump >= i && check[mid] + minJump <= i) {
                    check.push_back(i);
                    break;
                } else if (check[mid] + maxJump < i )
                    low = mid + 1;
                else if(check[mid] + minJump > i)
                    high = mid - 1;
            }
            if (check.back() + maxJump >= i && check.back() + minJump <= i)
                check.push_back(i);
        }
        if (check.back() == n - 1)
            return true;
        return false;
    }
};