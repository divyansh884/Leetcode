class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int n= nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        nums.clear();
        set<int>::iterator itr;
        for(itr= s.begin();itr!=s.end();itr++){
            nums.push_back(*itr);
        }
        return nums.size();
    }
};