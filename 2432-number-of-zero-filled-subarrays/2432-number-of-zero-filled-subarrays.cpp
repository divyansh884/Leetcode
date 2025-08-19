class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        int i=0,n=nums.size();
        bool check=false;
        for(int ind=0;ind<nums.size();ind++){
            if(nums[ind]==0){
                i=ind;
                check=true;
                break;
            }
        }
        if(!check)
        return sum;
        int j=i;
        vector<long long> ans;
        while(j<n){
            if(nums[j]!=0){
                ans.push_back(j-i);
                i=j;
                while(i<n && nums[i]!=0){
                    i++;
                }
                j=i;
            }
            else{
                j++;
            }
        }
        ans.push_back(j-i);
        for(int i=0;i<ans.size();i++){
            long long add=ans[i]*(ans[i]+1)/2;
            sum+=add;
        }
        return sum;
    }
};