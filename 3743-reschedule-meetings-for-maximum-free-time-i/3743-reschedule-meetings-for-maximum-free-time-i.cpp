class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> ans;
        int pre=0;
        int count=0;
        for(int i=0;i<startTime.size();i++){
            ans.push_back(startTime[i]-pre);
            pre=endTime[i];
        }
        ans.push_back(eventTime-pre);
        int re=0;
        for(int i=0;i<k+1 && i<ans.size();i++){
            re+=ans[i];
        }
        int maxi=re;
        int i=k+1;
        int j=0;
        while(i<ans.size()){
            re-=ans[j];
            re+=ans[i];
        i++;
        j++;
        maxi=max(re,maxi);
        }
        return maxi;
    }
};