class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            string add="";
            for(int i=0;i<word.size();i++){
                char c=word[i];
                if(c!='z'){
                    c++;
                    add+=c;
                }
                else
                add+='a';
            }
            word+=add;
        }
        return word[k-1];
    }
};