class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> mp;
        if(k>s.size())
        return false;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int count=0;
        for(auto i:mp){
            if(i.second%2!=0)
            count++;
        }
        if(count>k)
        return false;
        return true;
    }
};