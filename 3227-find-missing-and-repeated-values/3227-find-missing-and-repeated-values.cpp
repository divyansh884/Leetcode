class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a,b;
        unordered_map<int,int> mp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                mp[grid[i][j]]++;
            }
        }
        for(int i=1;i<=grid.size()*grid.size();i++){
            if(mp[i]==0)
            b=i;
            if(mp[i]==2)
            a=i;
        }
        return {a,b};
    }
};