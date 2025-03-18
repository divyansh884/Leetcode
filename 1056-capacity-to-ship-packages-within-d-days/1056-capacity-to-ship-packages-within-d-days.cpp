class Solution {
public:
int solve(vector<int>& weights, int days){
    int day=1;
    int temp=0;
    for( auto it: weights){
        
        if(temp+it>days){
        day++;
        temp=0;
        }
        temp+=it;
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int curr=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            int temp= solve(weights,mid);
            if(temp<=days){
                curr=mid;
                right=mid-1;
            }
            else
            left=mid+1;
        }
        return curr;
    }
};