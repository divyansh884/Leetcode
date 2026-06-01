class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int n=cost.size();
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i+=3){
            if(i+1<n)
            sum+=cost[i]+cost[i+1];
            else
            sum+=cost[i];
        }
        return sum;
    }
};