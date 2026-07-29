class Solution {
public:
    vector<vector<int>> generate(int nr) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(nr>1)
        ans.push_back({1,1});
        while(ans.size()<nr){
            int n=ans.size();
            vector<int> temp;
            temp.push_back(1);
            for(int i=0;i<ans[n-1].size()-1;i++){
                temp.push_back(ans[n-1][i]+ans[n-1][i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};