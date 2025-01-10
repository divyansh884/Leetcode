class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char,int> mp;
        for(int i=0;i<words2.size();i++){
            unordered_map<char,int> mp0;
            for(int j=0;j<words2[i].size();j++){
                mp0[words2[i][j]]++;
            }
            for(auto i:mp0){
                if(i.second>mp[i.first])
                mp[i.first]=i.second;
            }
        }
        for(int i=0;i<words1.size();i++){
            bool see= true;
            unordered_map<char,int> mp1;
            for(int j=0;j<words1[i].size();j++){
                mp1[words1[i][j]]++;
            }
            for( auto i:mp){
                if(i.second>mp1[i.first]){
                    see= false;
                }
            }
            if(see)
            ans.push_back(words1[i]);
        }
        return ans;
    }
};