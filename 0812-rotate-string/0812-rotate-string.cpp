class Solution {
public:
    bool rotateString(string s, string goal) {
        int st=-1;
        for(int i=0;i<goal.size();i++){
            if(goal[i]==s[0]){
            st=i;
            break;
            }
        }
        if(st==-1 || s.size()!=goal.size())
        return false;
        for(int i=0;i<goal.size();i++){
            if(goal[(i+st)%goal.size()]!=s[i]){
                return false;
            }
        }
        return true;
    }
};