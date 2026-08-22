class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int sum=0;
        int curr=0;
        for(auto it:requests){
            sum+=abs(it-curr);
            curr=it;
        }
        return sum;
    }
};