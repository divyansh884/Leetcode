class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> s;
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1]<=nums[2])
        return "none";
        for(auto i: nums){
            s.insert(i);
        }
        if(s.size()==3)
        return "scalene";
        else if(s.size()==2)
        return "isosceles";
        return "equilateral";
    }
};