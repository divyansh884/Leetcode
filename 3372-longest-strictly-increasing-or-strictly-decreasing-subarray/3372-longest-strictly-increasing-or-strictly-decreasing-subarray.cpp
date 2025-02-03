class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxcount=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int count=1;
            for(int j=i;j<nums.size()-1;j++){
                if(nums[j]<nums[j+1])
                count++;
                else{
                    maxcount=max(count,maxcount);
                    break;
                }
            }
            maxcount=max(count,maxcount);
        }
         for(int i=0;i<nums.size();i++){
            int count=1;
            for(int j=i;j<nums.size()-1;j++){
                if(nums[j]>nums[j+1])
                count++;
                else{
                    maxcount=max(count,maxcount);
                    break;
                }
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};