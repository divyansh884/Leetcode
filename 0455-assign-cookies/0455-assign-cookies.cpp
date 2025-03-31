class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=s.size()-1,cnt=0;
        if(s.size()==0)
        return cnt;
        for(int i=g.size()-1;i>=0;i--){
            if(g[i]<=s[j]){
                j--;
                cnt++;
            }
            if(j<0)
            break;
        }
        return cnt;
    }
};