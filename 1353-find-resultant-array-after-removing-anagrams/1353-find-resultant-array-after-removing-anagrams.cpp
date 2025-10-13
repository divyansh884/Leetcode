class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if(words.size()<=1)
        return words;
        set<string> st;
        vector<string> ans;
        int n=words.size();
        int i=0,j=1;
        while(j<n){
            string s1= words[i];
            string s2= words[j];
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1==s2)
            j++;
            else{
                ans.push_back(words[i]);
                i=j;
                j++;
            }
        }
        ans.push_back(words[i]);
        return ans;
    }
};