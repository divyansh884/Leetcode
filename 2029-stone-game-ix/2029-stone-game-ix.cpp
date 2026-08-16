class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            stones[i]=stones[i]%3;
            if(stones[i]==2)
            cnt2++;
            else if(stones[i]==1)
            cnt1++;
            else
            cnt0++;
        }
         if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};