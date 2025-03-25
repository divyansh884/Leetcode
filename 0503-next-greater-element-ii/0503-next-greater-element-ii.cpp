class Solution {
    vector<int> nextgreater(vector<int> nums,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr= nums[i];
        while(s.size()!=1 && s.top()<=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
        }
        return ans;
    }
    int prevcheck(stack<int> ans,int target){
        while(ans.size()!=0){
            if(ans.top()>target)
            return ans.top();
            ans.pop();
        }
        return -1;
    }
    bool check(int i,vector<int> nums){
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i])
            return false;
        }
        return true;
    }
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        vector<int> next(n);
        next= nextgreater(nums,n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            s.push(nums[i]);
        }
        for(int i=0;i<n;i++){
             if(next[i]==-1 && nums[i]>=0)
             next[i]=prevcheck(s,nums[i]);
             else if(next[i]==-1 && nums[i]<0 &&check(i,nums))
             next[i]=prevcheck(s,nums[i]);
        }
        return next;
    }
};