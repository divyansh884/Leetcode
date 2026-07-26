class Solution {
public:
    int solve(vector<int>& nums, int currentIndex, vector<int>& memo) {
        if (currentIndex >= nums.size() - 1) return 0;
        if (memo[currentIndex] != -1) return memo[currentIndex];
        
        int minJumps = nums.size() + 1;
        
        for (int step = nums[currentIndex]; step >= 1; --step) {
            int jumps = 1 + solve(nums, currentIndex + step, memo);
            minJumps = min(minJumps, jumps);
        }
        
        return memo[currentIndex] = minJumps;
    }

    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, 0, memo);
    }
};