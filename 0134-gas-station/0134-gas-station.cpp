class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        for(int i=0;i<gas.size();i++){
            sum+=(gas[i]-cost[i]);
        }
        if(sum<0)
        return -1;
        int curr_gas=0,starting_point;
        for(int i=0;i<gas.size();i++){
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0)
            {
                starting_point=i+1; 
                curr_gas=0;
            }
        }
        return starting_point;
    }
};