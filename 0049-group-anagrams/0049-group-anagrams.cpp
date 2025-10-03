class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int> mp;
        int cnt=0;
        for(int i=0;i<strs.size();i++){
            string re=strs[i];
            sort(re.begin(),re.end());
            if(mp.find(re)==mp.end()){
                mp[strs[i]]=cnt;
                mp[re]=cnt;
                cnt++;
            }
            else{
                mp[strs[i]]=mp[re];
            }
        }
        vector<vector<string>> ans(cnt);
        for(int i=0;i<strs.size();i++){
            ans[mp[strs[i]]].push_back(strs[i]);
        }
        return ans;
    }
};