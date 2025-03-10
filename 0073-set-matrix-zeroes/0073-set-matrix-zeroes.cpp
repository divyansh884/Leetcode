class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
       unordered_map<int,bool> mp,mp1;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                mp[i]=true;
                mp1[j]=true;
            }
        }
       } 
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i]==true){
                matrix[i][j]=0;
            }
        }
       }
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mp1[i]==true){
                matrix[j][i]=0;
            }
        }
       }
    }
};