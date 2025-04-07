class Solution {
public:
static bool comparator(vector<int> &v1, vector<int> &v2){
    return v1[1] < v2[1];
  }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         int i=0;
         int n=intervals.size();
        sort(intervals.begin(),intervals.end(), comparator);
         int removals = 0;
    int lastSeen = INT_MIN;
    for (vector<int> i: intervals){
      if (i[0] >= lastSeen){
        lastSeen = i[1];
      } else {
        removals+=1;
      }
    }
        return removals;
    }
};