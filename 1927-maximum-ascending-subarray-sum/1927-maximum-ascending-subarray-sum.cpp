class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cn=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j-1]<nums[j]){
                    cn+=nums[j];
                }
                else{
                sum=max(cn,sum);
                break;
                }
            }
            sum= max(cn,sum);
        }
        return sum;
    }
};