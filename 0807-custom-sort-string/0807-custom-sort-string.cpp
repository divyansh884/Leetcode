class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        string sn="";
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<order.size();i++){
            while(mp[order[i]]>0){
            sn+=order[i];
            mp[order[i]]--;
            }
        }
        for( auto &i:mp){
            while(i.second>0){
                sn+=i.first;
                i.second--;
            }

        }
        return sn;
    }
};