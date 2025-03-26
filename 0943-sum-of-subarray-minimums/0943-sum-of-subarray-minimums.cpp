
class Solution {
public:
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
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> next=nextsamller(arr);
        vector<int> prev=prevsamller(arr);
        int ans=0;
         int mod = 1e9 + 7;
        for(int i=0;i<arr.size();i++){
            int left=i-prev[i];
            int right=next[i]-i;
            ans=(ans+(1LL*right*left*arr[i])%mod)%mod;
        }
        return ans;
    }
};