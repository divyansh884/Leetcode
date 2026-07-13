class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            int num = i;
            if (num >= low && num <= high)
                ans.push_back(num);
            for (int j = i + 1; j <= 9; j++) {
                if (num * 10 + j <= high) {
                    num = num * 10 + j;
                } else
                    break;
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};