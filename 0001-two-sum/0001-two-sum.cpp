class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> add;
        for(int i=0;i<nums.size();i++){
            for(int j= i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    add.push_back(i);
                    add.push_back(j);
                    break;
                }
            }
        }
        return add;
    }
};