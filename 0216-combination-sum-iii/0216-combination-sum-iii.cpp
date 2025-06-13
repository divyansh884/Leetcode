class Solution {
public:
void solve(int index,int &sum, vector<vector<int>> &ans,int k, int n,vector<int> &qd){
    if(qd.size()==k){
        if(sum==n)
        ans.push_back(qd);
        return;
    }
    if(sum>=n && qd.size()<k)
    return;
    if(sum<n && qd.size()>=k)
    return;
    for(int i=index;i<=9;i++){
        qd.push_back(i);
        sum+=i;
        solve(i+1,sum,ans,k,n,qd);
        sum-=i;
        qd.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int sum=0;
        int index=1;
        vector<int> qd;
        solve(index,sum,ans,k,n,qd);
        return ans;
    }
};