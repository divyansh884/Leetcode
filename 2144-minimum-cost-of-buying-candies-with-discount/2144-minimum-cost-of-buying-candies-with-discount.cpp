class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int n=cost.size();
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(cnt==2){
                cnt=0;
                continue;
            }
            sum+=cost[i];
            cnt++;
        }
        return sum;
    }
};