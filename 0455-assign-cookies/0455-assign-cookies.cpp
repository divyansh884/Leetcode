class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)
        return 0;
        sort(s.begin(),s.end(),greater<int>());
        sort(g.begin(),g.end(),greater<int>());
        int index=0;
        int cnt=0;
        for(int i=0;i<g.size();i++){
            if(g[i]<=s[index]){
                index++;
                cnt++;
            }
            if(index>=s.size())
            break;
        }
        return cnt;
    }
};