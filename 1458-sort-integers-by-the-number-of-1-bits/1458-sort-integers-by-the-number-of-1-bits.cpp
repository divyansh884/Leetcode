class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> vec(33,vector<int>());
        for( int i=0;i<arr.size();i++){
            int cnt=0;
            for(int j=0;j<32;j++){
                if((arr[i]>>j)&1)
                cnt++;
            }
            vec[cnt].push_back(arr[i]);
        }
        vector<int> ans;
        for(int i=0;i<33;i++){
            for(int j=0;j<vec[i].size();j++){
                ans.push_back(vec[i][j]);
            }
        }
        return ans;
    }
};