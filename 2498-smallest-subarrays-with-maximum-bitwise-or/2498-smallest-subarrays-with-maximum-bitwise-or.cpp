class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> vec(32, 0),vec1(32,0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if((nums[i]>>j)&1)
                vec[j]++;
            }
        }
        vector<int> ans(n);
        int i=0,j=0;
        while(j<n && i<n){
            bool check=true;
            for( int it=0;it<32;it++){
                if(vec[it]!=0 && vec1[it]==0){
                    check=false;
                    break;
                }
            }
            if(!check){
                for(int it=0;it<32;it++){
                    if((nums[j]>>it)&1)
                    vec1[it]++;
                }
                j++;
            }
            else{
                if(j==i)
                j++;
                ans[i]=j-i;
                for(int it=0;it<32;it++){
                    if((nums[i]>>it)&1){
                        vec[it]--;
                        vec1[it]--;
                    }
                }
                i++;
            }
        }
        while(i<n){
            if(j==i)
                j++;
            ans[i]=j-i;
            i++;
        }
        return ans;
    }
};