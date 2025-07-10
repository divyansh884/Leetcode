class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
         vector<int> ans;
        int pre=0;
        int count=0;
        unordered_map<int,int> pref,suff;
        int premax=0;
        for(int i=0;i<startTime.size();i++){
            ans.push_back(startTime[i]-pre);
            ans.push_back(abs(startTime[i]-endTime[i]));
            pre=endTime[i];
        }
        ans.push_back(eventTime-pre);
        for(int i=0;i<ans.size();i++){
            if(i%2==0)continue;
            pref[i]=premax;
            premax=max(premax,ans[i-1]);
        }
        int sufmax=0;
        for(int i=ans.size()-1;i>=0;i--){
            if(i%2==0)continue;
            suff[i]=sufmax;
            sufmax=max(sufmax,ans[i+1]);
        }
        int maxi=0;
        for(int i=0;i<ans.size();i++){
            if(i%2==0)continue;
            int re=0;
            if(pref[i]>=ans[i]|| suff[i]>=ans[i]){
                re+=ans[i];
            }
            re+=ans[i-1];
            re+=ans[i+1];
            maxi=max(re,maxi);
        }
        return maxi;
    }
};