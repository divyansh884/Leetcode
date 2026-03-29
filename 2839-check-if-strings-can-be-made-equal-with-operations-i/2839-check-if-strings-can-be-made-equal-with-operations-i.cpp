class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<2;i++){
            string ss1="";
            string ss2="";
            ss1+=s1[i];
            ss1+=s1[i+2];
            ss2+=s2[i];
            ss2+=s2[i+2];
            sort(ss1.begin(),ss1.end());
            sort(ss2.begin(),ss2.end());
            if(ss1!=ss2)
            return false;
        }
        return true;
    }
};