class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int> mp;
        unordered_map<char,int> sh;
        for(auto it: word){
            if(it>='a' && it<='z' && sh[it]==0){
            mp[it-'a']++;
            sh[it]++;
            }
            else if(it>='A' && it<='Z' && sh[it]==0){
            mp[it-'A']++;
            sh[it]++;
            }
        }
        int cnt=0;
        for(auto it: mp){
            if(it.second>1)
            cnt++;
        }
        return cnt;
    }
};