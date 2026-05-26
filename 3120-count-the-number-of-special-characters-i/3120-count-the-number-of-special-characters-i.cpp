class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        map<char,int>m;
        for(int i=0;i<n;i++){
            m[word[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z' && m[word[i]]>0){
                if(m[word[i]]>=1 && m[toupper(word[i])]>=1){
                    count++;
                    m[word[i]]=0;
                }
            }
        }
        return count;
    }
};