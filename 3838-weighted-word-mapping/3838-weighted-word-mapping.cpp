class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<char> ch(26);
        int i=0;
        for(char c='z';c>='a';c--){
            ch[i]=c;
            i++;
        }
        string ans="";
        for(auto it: words){
            int sum=0;
            for(int i=0;i<it.size();i++){
                sum+=weights[it[i]-'a'];
            }
            int add=sum%26;
            ans.push_back(ch[add]);
        }
        return ans;
    }
};