class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int> mp1,mp2;
       for( auto it :ransomNote){
        mp1[it]++;
       }
       for( auto it :magazine){
        mp2[it]++;
       }
       for( auto it :ransomNote){
        if(mp1[it]>mp2[it])
        return false;
       }
       return true;
    }
};