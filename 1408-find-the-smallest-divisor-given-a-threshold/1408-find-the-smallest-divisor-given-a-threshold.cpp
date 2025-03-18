class Solution {
public:
int solve(vector<int>& nums, int mid) {
        int ans = 0;
        for (int i : nums) {
            ans += (i + mid - 1) / mid; 
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int low=1;
       int ans=-1;
       int high = *max_element(nums.begin(), nums.end());
       while(low<=high){
        int mid=low+(high-low)/2;
        int sum=solve(nums, mid);
        if(sum<=threshold){
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
       }
       return ans;
    }
};