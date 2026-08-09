class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> a;
        for (int i = 0; i < pow(2, nums.size()); i++) {
            vector<int> temp;
            for(int j=0;j<32;j++){
                if((i>>j)&1)
                temp.push_back(nums[j]);
            }
            a.insert(temp);
        }
        vector<vector<int>> ans(a.begin(),a.end());
        return ans;
    }
};