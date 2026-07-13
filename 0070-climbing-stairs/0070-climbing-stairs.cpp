class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(n+1,-1);
        vec[0]=1;
        for(int i=1;i<=n;i++){
            vec[i]=vec[i-1];
            if(i-2>=0)
            vec[i]+=vec[i-2];
        }
        return vec[n];
    }
};