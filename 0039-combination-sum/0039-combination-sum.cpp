class Solution {
public:
void solve(int index,vector<int> &ds,vector<int> arr,int &sum,int k,int n,vector<vector<int>> &ans ){
    if(sum==k){
        ans.push_back(ds);
        return;
    }
    if(sum>k)
    return;
    if(index>=n){
        if(sum==k){
        ans.push_back(ds);
    }
    return;
    }
    ds.push_back(arr[index]);
    sum+=arr[index];
    solve(index,ds,arr,sum,k,n, ans);
    sum-=arr[index];
    ds.pop_back();
    solve(index+1,ds,arr,sum,k,n, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index=0,sum=0,n=candidates.size();
        solve(index,ds,candidates,sum,target,n, ans);
        return ans;
    }
};