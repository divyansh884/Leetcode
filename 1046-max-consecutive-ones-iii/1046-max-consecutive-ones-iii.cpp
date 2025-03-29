class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0,j=0,n=nums.size(),ans=-1;
        while(j<n){
            if(nums[j]==1){
                if(nums[i]==0 && k==0)
                i=j;
                ans=max(ans,j-i+1);
                j++;
            }
            else if(nums[j]==0 && k!=0){
                dq.push_back(j);
                ans=max(ans,j-i+1);
                j++;
                k--;
            }
            else{
                if(!dq.empty()){
                int temp=dq.front();
                i=temp+1;
                cout<<temp;
                dq.pop_front();
                dq.push_back(j);
                ans=max(ans,j-i+1);
                j++;
                }
                else{
                    j++;
                }
            }
        }
        if(ans==-1)
        return 0;
        return ans;
    }
};