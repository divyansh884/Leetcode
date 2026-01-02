class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0, num = nums[0];
        int n = nums.size() / 2;
        cout << n << endl;
        for (auto it : nums) {
            if (it == num)
                cnt++;
            else {
                if (cnt == n)
                    return num;
                else {
                    num = it;
                    cnt = 1;
                }
            }
        }
        if (cnt == n)
            return num;
        return -1;
    }
};