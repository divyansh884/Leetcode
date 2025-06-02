class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=1;
        int ans=0;
        while(x<=max(start,goal)){
            if((start&x)!=(goal&x)){
                ans++;
            }
            x<<=1;
        }
        return ans;
    }
};