class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> mp,tp;

        for(auto c:t)
            tp[c]++;

        int i=0,j=0;
        int start=-1,minLen=INT_MAX;

        while(j<s.size()){

            mp[s[j]]++;

            bool check=true;

            for(auto it:tp){
                if(mp[it.first] < it.second){
                    check=false;
                    break;
                }
            }

            while(check){

                if(minLen > j-i+1){
                    minLen = j-i+1;
                    start = i;
                }

                mp[s[i]]--;
                i++;

                for(auto it:tp){
                    if(mp[it.first] < it.second){
                        check=false;
                        break;
                    }
                }
            }

            j++;
        }

        if(start==-1) return "";
        return s.substr(start,minLen);
    }
};