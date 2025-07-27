class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> vec;
        int prev=-1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]!=prev) {
                vec.push_back(nums[i]);
                prev=nums[i];
            }
        }
       int cnt=0;
       for(int i=1;i<vec.size()-1;i++){
        if(vec[i]>vec[i-1] && vec[i]>vec[i+1])
        cnt++;
        else if(vec[i]<vec[i-1] && vec[i]<vec[i+1])
        cnt++;
       }
       return cnt;
    }
};