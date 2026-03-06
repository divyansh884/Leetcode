class Solution {
public:
void f(set<vector<int>> &ans,vector<int> &temp,vector<int> &nums,int i){
    if(i==nums.size()){
        ans.insert(temp);
        return;
    }
    temp.push_back(nums[i]);
    f(ans,temp,nums,i+1);
    temp.pop_back();
    f(ans,temp,nums,i+1);
 }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> a;
        vector<int> temp;
        int i=0;
        f(a,temp,nums,i);
        vector<vector<int>> ans(a.begin(),a.end());
        return ans;
    }
};