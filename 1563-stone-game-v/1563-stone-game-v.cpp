class Solution {
public:
    int f(int i, int j, vector<int>& arr, vector<int>& pre,
          vector<vector<int>>& dp) {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int sum = 0;
        int tot = pre[j];
        if (i != 0)
            tot -= pre[i - 1];
        int maxi = 0;
        for (int ind = i; ind <= j; ind++) {
            sum += arr[ind];
            int left = tot - sum;
            if (sum < left) {
                int temp = sum + f(i, ind, arr, pre, dp);
                maxi=max(maxi,temp);
            } else if (sum > left) {
                int temp1 = left + f(ind + 1, j, arr, pre, dp);
                maxi=max(maxi,temp1);
            } else {
                int temp2 = sum + f(i, ind, arr, pre, dp);
                int temp3 = left + f(ind + 1, j, arr, pre, dp);
                maxi=max(maxi,max(temp2,temp3));
            }
        }
        return dp[i][j]=maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> pre(n);
        pre[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+stoneValue[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,n-1,stoneValue,pre,dp);
    }
};