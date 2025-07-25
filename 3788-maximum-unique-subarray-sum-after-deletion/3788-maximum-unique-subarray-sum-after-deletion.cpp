class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int key = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (key != nums[i] && nums[i] > 0) {
                if (key > 0)
                    sum += key;
                key = nums[i];
            } else if (key != nums[i] && nums[i] <= 0)
                key = nums[i];
        }
        sum += key;
        return sum;
    }
};