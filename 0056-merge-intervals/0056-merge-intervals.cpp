class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int i=0;
        while(i<n){
            int st=intervals[i][0];
            int ed=intervals[i][1];
            int j=i+1;
            while(j<n && ed>=intervals[j][0]){
                ed= max(ed,intervals[j][1]);
                j++;
            }
            i=j;
            ans.push_back({st,ed});
        }
        return ans;
    }
};