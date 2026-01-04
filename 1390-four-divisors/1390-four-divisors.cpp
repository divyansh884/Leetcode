class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            int sum=0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    sum+=j;
                    cnt++;
                    int div=nums[i]/j;
                    if(div!=j){
                        sum+=div;
                        cnt++;
                    }
                    if(cnt>4)
                    break;
                }
            }
            if(cnt==4)
            ans+=sum;
        }
        return ans;
    }
};