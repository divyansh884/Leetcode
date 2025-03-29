class Solution {
public:
int atmost(vector<int>& nums, int k){
    int i=0,j=0,ans=0,n=nums.size(),count=0;
    while(j<n){
        if(nums[j]%2!=0){
            count++;
        }
        while(count>k){
            if(nums[i]%2!=0)
            count--;
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};