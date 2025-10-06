class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,bool> mrow,mcol;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    mrow[i]=true;
                    mcol[j]=true;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(mrow.find(i)!=mrow.end()|| mcol.find(j)!=mcol.end()){
                    matrix[i][j]=0;
                }
            }
        }
    }
};