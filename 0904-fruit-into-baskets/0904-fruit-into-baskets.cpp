class Solution {
public:
    int totalFruit(vector<int>& s) {
         unordered_map<int,int> mp;
        int i=0,j=0;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()>2){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            ans= max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};