class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0,j=0,n=nums.size(),ans=-1;
        if(k==0){
            int count=0;
            for(int i=0;i<n;i++){
                if(nums[i]==1)
               count++;
               else{
               ans=max(count,ans);
               count =0;
               }
            }
            ans=max(count,ans);
            return ans;
        }
        while(j<n){
            if(nums[j]==1){
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