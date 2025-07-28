class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans|nums[i]);
        }
        int cnt=0;
        for(int i=0;i<pow(2,n);i++){
            int check=0;
            for( int j=0;j<32;j++){
                if((i>>j)&1)
                check=(check|nums[j]);
            }
            if(check==ans)
            cnt++;
        }
        return cnt;
    }
};