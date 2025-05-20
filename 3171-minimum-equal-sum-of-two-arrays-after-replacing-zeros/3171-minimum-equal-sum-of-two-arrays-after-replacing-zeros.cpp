class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,cnt01=0,cnt02=0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            if(nums1[i]==0)
            cnt01++;
        }
        for(int i=0;i<nums2.size();i++){
            sum2+=nums2[i];
            if(nums2[i]==0)
            cnt02++;
        }
        if(sum1==sum2){
        if(cnt01==0 && cnt02==0)
        return sum1;
        }
        if(cnt01==0 || cnt02==0){
            if(sum1<sum2 && cnt01!=0 && cnt01<=abs(sum1-sum2)){
                return sum2;
            }
            else if(sum1>sum2 && cnt02!=0 && cnt02<=abs(sum1-sum2)){
                return sum1;
            }
            else
            return -1;
        }
        sum1+=cnt01-1;
        sum2+=cnt02-1;
        long long ans= max(sum1,sum2);
        return ans+1;
    }
};