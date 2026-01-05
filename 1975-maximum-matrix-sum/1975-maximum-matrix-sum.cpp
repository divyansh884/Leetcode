class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int n= matrix.size();
        int mini=1e9;
        for(int i=0;i<n-1;i++){
            for( int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    matrix[i][j]*=-1;
                    matrix[i+1][j]*=-1;
                }
                sum+=abs(matrix[i][j]);
                mini= min(mini,abs(matrix[i][j]));
            }
        }
        int neg=0;
        for(int i=0;i<n-1;i++){
            if(matrix[n-1][i]<0){
                matrix[n-1][i]*=-1;
                matrix[n-1][i+1]*=-1;
            }
            sum+=abs(matrix[n-1][i]);
            mini= min(mini,abs(matrix[n-1][i]));
        }
        sum+=abs(matrix[n-1][n-1]);
        mini= min(mini,abs(matrix[n-1][n-1]));
        if(matrix[n-1][n-1]<0)
        sum-=2*mini;
        return sum;
    }
};