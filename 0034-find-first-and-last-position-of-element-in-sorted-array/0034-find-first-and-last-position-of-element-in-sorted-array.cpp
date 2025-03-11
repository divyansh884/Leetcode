class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> t;
        vector<int> t1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                t.push_back(i);
            }
        }
        if(t.empty()){
            t.push_back(-1);
            t.push_back(-1);
        }
        if(t.size()!=2){
            t1.push_back(t[0]);
            t1.push_back(t[t.size()-1]);
            return t1;
        }
        return t;
    }
};