class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        set<int> st;
        int odd=0,eve=0,n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            for( int j=i;j<n;j++){
                if(st.find(nums[j])==st.end()){
                    if(nums[j]%2==0)
                    eve++;
                    else
                    odd++;
                    st.insert(nums[j]);
                }
                if(eve==odd)
                ans=max(ans,j-i+1);
            }
            st.clear();
            eve=0;
            odd=0;
        }
        return ans;
    } 
};