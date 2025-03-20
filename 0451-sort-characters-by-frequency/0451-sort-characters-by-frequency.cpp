class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mapping;
        for(int i=0;i<s.size();i++){
            mapping[s[i]]++;
        }
        vector<pair<int,char>> vp;
        for(auto it:mapping){
            vp.push_back(make_pair(it.second,it.first));
        }
        sort(vp.begin(),vp.end(),[](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first; 
        } else {
            return a.second < b.second;
        }
    });
    string rs="";
    for(int i=0;i<vp.size();i++){
        while(vp[i].first--)
        rs+=vp[i].second;
    }
    return rs;
    }
};