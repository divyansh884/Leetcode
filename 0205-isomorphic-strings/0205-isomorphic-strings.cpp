class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,bool> mp1;
        unordered_map<char,bool> mp2;
        for(int i=0;i<s.size();i++){
            if(mp1[s[i]]==true && mp[s[i]]!=t[i]){
                return false;
            }
            else if(mp1[s[i]]!=true){
                mp1[s[i]]=true;
                if(mp2[t[i]]==true)
                return false;
                mp2[t[i]]=true;
                mp[s[i]]=t[i];
            }
        }
        return  true;
    }
};