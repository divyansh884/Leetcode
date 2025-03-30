class Solution {
public:
    string minWindow(string s, string t) {
       int i=0,j=0,cnt=0,minlen=INT_MAX,stindex=-1;
       unordered_map<int,int> mp;
       for( int m=0;m<t.size();m++){
        mp[t[m]]++;
       }
       while(j<s.size()){
        if(mp[s[j]]>0)cnt++;
        mp[s[j]]--;
        while(cnt==t.size()){
            if(j-i+1<minlen){
                minlen=j-i+1;
                stindex=i;
            }
            mp[s[i]]++;
            if(mp[s[i]]>0)cnt--;
            i++;
        }
        j++;
       }
       return stindex== -1? "":s.substr(stindex,minlen);
    }
};