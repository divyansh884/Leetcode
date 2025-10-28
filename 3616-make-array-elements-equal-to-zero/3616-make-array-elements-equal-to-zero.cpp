class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int cnt=0,n=nums.size();
        vector<int> sum(n);
        sum[0]=nums[0];
        for(int i=1;i<n;i++){
            sum[i]=nums[i]+sum[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0 && sum[i]==sum[n-1]-sum[i])
            cnt+=2;
            else if(nums[i]==0 && abs(sum[i]-(sum[n-1]-sum[i]))==1)
            cnt++;
        }
        return cnt;
    }
};