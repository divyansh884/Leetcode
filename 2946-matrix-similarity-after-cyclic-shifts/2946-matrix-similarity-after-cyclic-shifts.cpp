class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> mats=mat;
       int m=mat.size();
       int n=mat[0].size();
       k=(k%n);
       for(int i=0;i<m;i++){
        reverse(mat[i].begin(),mat[i].end());
        reverse(mat[i].begin(),mat[i].begin()+k);
        reverse(mat[i].begin()+k,mat[i].end());
       }
       return mat==mats;
    }
};