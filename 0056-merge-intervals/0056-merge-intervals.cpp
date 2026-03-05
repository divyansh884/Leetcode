class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;){
            int j=i+1;
            int st=intervals[i][0];
            int ed=intervals[i][1];
            while(j<n && intervals[j][0]<=ed){
                ed= max(ed,intervals[j][1]);
                j++;
            }
            ans.push_back({st,ed});
            i=j;
        }
        return ans;
    }
};