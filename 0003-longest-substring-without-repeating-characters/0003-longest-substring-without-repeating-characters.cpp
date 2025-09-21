class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        int cnt=1;
        int i=0,j=i+1;
        unordered_map<char,int> mp;
        mp[s[i]]=i;
        while(j<s.size()){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]=j;
            }
            else{
                while(i<=mp[s[j]]){
                    mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]=j;
            }
            cnt=max(cnt,j-i+1);
            j++;
        }
        return cnt;
    }
};