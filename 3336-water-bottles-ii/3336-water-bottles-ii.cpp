class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int sum=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
           empty-=(numExchange-1);
           numExchange++;
           sum++;
        }
        return sum;
    }
};