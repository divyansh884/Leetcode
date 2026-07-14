class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)
        return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int index=0;
        int i=0;
        int cnt=0;
        while(i<g.size()){
            if(g[i]<=s[index]){
                index++;
                i++;
                cnt++;
            }
            else if(g[i]>s[index])
            index++;
            if(index>=s.size())
            break;
        }
        return cnt;
    }
};