class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> ans;
        unordered_map<int,int> color;
        unordered_map<int,bool> balls;
        unordered_map<int,int> label;
        int count=0;
        for(int i=0;i<n;i++){
            if(balls[queries[i][0]]!=true && color[queries[i][1]]<=0){
            count++;
            balls[queries[i][0]]=true;
            color[queries[i][1]]++;
            label[queries[i][0]]=queries[i][1];
            }
            else if(balls[queries[i][0]]==true && color[queries[i][1]]>0){
                color[queries[i][1]]++;
                color[label[queries[i][0]]]--;
                if(color[label[queries[i][0]]]<=0)
                count--;
                label[queries[i][0]]=queries[i][1];
            }
            else if(balls[queries[i][0]]!=true && color[queries[i][1]]>0){
                color[queries[i][1]]++;
                balls[queries[i][0]]=true;
                label[queries[i][0]]=queries[i][1];
            }
            else{
                color[queries[i][1]]++;
                count++;
                color[label[queries[i][0]]]--;
                if(color[label[queries[i][0]]]<=0){
                count--;
                }
                label[queries[i][0]]=queries[i][1];
            }
            ans.push_back(count);
        }
        return ans;
    }
};