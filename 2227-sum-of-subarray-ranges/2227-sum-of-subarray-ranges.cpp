class Solution {
public:
vector<int> nextgreater(vector<int> nums,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n,n);
        for(int i=n-1;i>=0;i--){
            int curr= nums[i];
        while(s.size()!=1 && nums[s.top()]<curr){
            s.pop();
        }
        if(s.top()!=-1)
        ans[i]=s.top();
        s.push(i);
        }
        return ans;
    }
    vector<int> prevgreater(vector<int> nums,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int curr= nums[i];
        while(s.size()!=1 && nums[s.top()]<=curr){
            s.pop();
        }
        if(s.top()!=-1)
        ans[i]=s.top();
        s.push(i);
        }
        return ans;
    }
    vector<int> nextsamller(vector<int>& arr){
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--){
        while(st.top()!=-1 && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.top()==-1)
        ans[i]=arr.size();
        else
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevsamller(vector<int>& arr){
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size(),0);
    
    for(int i=0;i<arr.size();i++){
        while(st.top()!=-1 && arr[st.top()]>arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> next=nextgreater(arr,arr.size());
        vector<int> prev=prevgreater(arr,arr.size());
        long long ans=0;
         int mod = 1e9 + 7;
        for(int i=0;i<arr.size();i++){
            long  left=i-prev[i];
            long  right=next[i]-i;
            ans=(ans+(right*left*arr[i]));
        }
        return ans;
    }
     long long sumSubarrayMins(vector<int>& arr) {
        vector<int> next=nextsamller(arr);
        vector<int> prev=prevsamller(arr);
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            long long  left=i-prev[i];
            long long right=next[i]-i;
            ans=(ans+(right*left*arr[i]));
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (sumSubarrayMaxs(nums)-sumSubarrayMins(nums));
    }
};