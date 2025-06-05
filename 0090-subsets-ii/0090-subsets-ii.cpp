class Solution {
public:
void solve(int index,vector<int> &ds,vector<int> &arr,int n,vector<vector<int>> &ans){
        ans.push_back(ds);
    for(int i=index;i<n;i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        solve(i+1,ds,arr,n ,ans);
        ds.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int index=0,n=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(index,ds,nums,n ,ans);
        return ans;
    }
};