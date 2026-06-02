class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst,
                           vector<int>& wd) {
        int n = lst.size();
        int ans=1e9;
        int m = wst.size();
        for (int i = 0; i < n; i++) {
            int st = lst[i];
            int ed = lst[i] + ld[i];
            for (int j = 0; j < m; j++) {    
                int temp=0;;
                if(st<=wst[j]){
                    temp=ed;
                    if(temp<wst[j]){
                        temp=wst[j];
                    }
                    temp+=wd[j];
                }
                else{
                    temp=wst[j]+wd[j];
                    if(temp<st){
                        temp=st;
                    }
                    temp+=ld[i];
                }
                ans=min(ans,temp);
            }
        }
        return ans;
    }
};