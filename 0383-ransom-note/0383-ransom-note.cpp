class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> mp;
        for(int i=0;i<magazine.size();i++){
            mp[magazine[i]]++;
        }
        for(int j=0;j<ransomNote.size();j++){
            if(mp.find(ransomNote[j])==mp.end())
            return false;
            if(mp[ransomNote[j]]==0)
            return false;
            else
            mp[ransomNote[j]]--;
        }
        return true;
    }
};