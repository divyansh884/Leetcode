class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell= prices[0];
        int n=prices.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(prices[i]>sell){
                maxi=max(maxi,prices[i]-sell);
            }
            else
            sell=prices[i];
        }
        return maxi;
    }
};