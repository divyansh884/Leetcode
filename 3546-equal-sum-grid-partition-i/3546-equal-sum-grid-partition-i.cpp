class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> rowsum,colsum;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
            }
            if(rowsum.empty())
            rowsum.push_back(sum);
            else
            rowsum.push_back(sum+rowsum.back());
        }
        for(int i=0;i<rowsum.size()-1;i++){
            if(rowsum.back()%2==0 && rowsum.back()/2==rowsum[i])
            return true;
        }
         for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++){
                sum+=grid[j][i];
            }
            if(colsum.empty())
            colsum.push_back(sum);
            else
            colsum.push_back(sum+colsum.back());
        }
        for(int i=0;i<colsum.size()-1;i++){
            if(colsum.back()%2==0 && colsum.back()/2==colsum[i])
            return true;
        }
        return false;
    }
};