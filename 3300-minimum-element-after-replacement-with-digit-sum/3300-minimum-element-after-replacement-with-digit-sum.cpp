class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=1e9,n=nums.size();
        for(int i=0;i<n;i++){
            int temp=nums[i];
            int cnt=0;
            while(temp!=0){
                int add=temp%10;
                cnt+=add;
                temp/=10;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};