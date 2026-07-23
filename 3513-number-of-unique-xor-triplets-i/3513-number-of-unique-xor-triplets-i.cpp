class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
        return n;
        int carr=0;
        for(int i=0;i<32;i++){
            if((n>>i)&1)
            carr=i;
        }
        int temp=0;
        for(int i=0;i<=carr;i++){
            temp+=(1<<i);
        }
        return temp+1;
    }
};