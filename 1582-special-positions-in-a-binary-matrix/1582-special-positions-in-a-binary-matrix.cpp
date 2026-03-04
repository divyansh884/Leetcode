class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        vector<pair<int,int>> vec;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)
                vec.push_back({i,j});
            }
        }
        for(int i=0;i<vec.size();i++){
            int row=vec[i].first;
            int col=vec[i].second;
            bool check=true;
            for(int j=0;j<mat[0].size();j++){
                if(mat[row][j]==1 && j!=col){
                    check=false;
                    break;
                }
            }
            if(!check)
            continue;
            for(int j=0;j<mat.size();j++){
                if(mat[j][col]==1 && j!=row){
                    check=false;
                    break;
                }
            }
            if(check)
            cnt++;
        }
        return cnt;
    }
};