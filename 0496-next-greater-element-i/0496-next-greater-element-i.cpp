class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int,int> mp;
        st.push(-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.size()!=1 && nums2[i]>st.top()){
                st.pop();
            }
            mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};