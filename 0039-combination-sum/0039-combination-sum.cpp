class Solution {
public:
void f(set<vector<int>> &st,vector<int> &temp, int i,vector<int> &arr,int target){
    if(i==arr.size()){
        if(target==0)
        st.insert(temp);
        return;
    }
    if(target-arr[i]>=0){
    temp.push_back(arr[i]);
    f(st,temp,i,arr,target-arr[i]);
    temp.pop_back();
    }
    f(st,temp,i+1,arr,target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> st;
        vector<int> temp;
        int i=0,tt=target;
        f(st,temp,i,candidates,tt);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};