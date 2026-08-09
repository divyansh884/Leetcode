class Solution {
public:
    void f(int i, vector<int>& temp, int& sum, set<vector<int>>& ans,
           int& target, vector<int>& arr) {
        if (sum == target) {
            ans.insert(temp);
            return;
        }
        if (sum > target)
            return;
        if (i >= arr.size()) {
            return;
        }
        for (int j = i; j < arr.size(); j++) {
            temp.push_back(arr[j]);
            sum += arr[j];
            f(j, temp, sum, ans, target, arr);
            temp.pop_back();
            sum -= arr[j];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        int sum=0;
        f(0, temp, sum, ans, target, candidates);
        vector<vector<int>> vec;
        for(auto it: ans)
        vec.push_back(it);
        return vec;
    }
};