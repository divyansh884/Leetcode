class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        while(numBottles!=0){
            int re=0;
            if(numBottles>numExchange)   
            re=numBottles%numExchange;
            int add= numBottles/numExchange;
            sum+=add;
            numBottles/=numExchange;
            numBottles+=re;
        }
        return sum;
    }
};