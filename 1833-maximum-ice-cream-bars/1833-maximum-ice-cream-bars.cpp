class Solution {
public:
    int maxIceCream(vector<int>& cost, int coins) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(coins-cost[i]>=0){
                coins-=cost[i];
                cnt++;
            }
            else
            break;
        }
        return cnt;
    }
};