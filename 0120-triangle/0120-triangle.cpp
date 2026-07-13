class Solution {
public:
    int minimumTotal(vector<vector<int>>& tg) {
        int m = tg.size();
        for (int i = 1; i < m; i++) {
            tg[i][0] += tg[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            tg[i][tg[i].size()-1] += tg[i - 1][tg[i].size()-2];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < tg[i].size()-1; j++) {
                int temp = tg[i][j];
                tg[i][j] = min(tg[i - 1][j], tg[i - 1][j - 1]) + temp;
            }
        }
        int ans=tg[m-1][0];
        for(int i=0;i<tg[m-1].size();i++){
            ans=min(ans,tg[m-1][i]);
        }
        return ans;
    }
};