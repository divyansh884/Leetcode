class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<int,int>>> vec(n,vector<pair<int,int>>(m,{0,0}));
        for(int j=0;j<m;j++){
            for( int i=0;i<n;i++){
                if(grid[i][j]=='X')
                vec[i][j].first++;
                else if(grid[i][j]=='Y')
                vec[i][j].second++;
                if(i>0){
                    vec[i][j].first+=vec[i-1][j].first;
                    vec[i][j].second+=vec[i-1][j].second;
                }
            }
        }
        int cnt=0;
        for( int i=0;i<n;i++){
            int sum1=0;
            int sum2=0;
            for(int j=0;j<m;j++){
                sum1+=vec[i][j].first;
                sum2+=vec[i][j].second;
                if(sum1==sum2 && sum1!=0)
                cnt++;
            }
        }
        return cnt;
    }
};