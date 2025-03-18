class Solution {
public:
long long int solve(vector<int>& piles, int mid){
    long long int count=0;
    for(auto it: piles){
        count+=(it+mid-1)/mid;
    }
    return count;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long int temp=solve(piles,mid);
            if(temp<=h){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};