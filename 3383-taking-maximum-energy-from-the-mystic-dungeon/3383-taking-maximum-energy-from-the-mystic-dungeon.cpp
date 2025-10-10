class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> suffixsum(n);
        suffixsum[n-1]=energy[n-1];
        int ans=suffixsum[n-1];
        for(int i=n-2;i>=0;i--){
            int add=i+k;
            if(add<=n-1){
                suffixsum[i]=suffixsum[add]+energy[i];
            }
            else{
                suffixsum[i]=energy[i];
            }
            ans= max(ans,suffixsum[i]);
        }
        return ans;
    }
};