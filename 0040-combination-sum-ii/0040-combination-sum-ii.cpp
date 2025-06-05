class Solution {
public:
void solve(int index,vector<int> &ds,vector<int> arr,int k,int n,vector<vector<int>> &ans ){
    if(k==0){
        ans.push_back(ds);
        return;
    }
    for(int i=index;i<n;i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]>k) break;
        ds.push_back(arr[i]);
        solve(i+1,ds,arr,k-arr[i],n, ans);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index=0,sum=0,n=candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(index,ds,candidates,target,n, ans);
        return ans;
    }
};