class Solution {
public:
    bool vowel(char &c) {
        if(c=='a'|| c=='e' || c=='i' || c=='o'|| c=='u')
        return true;
        if(c=='A'|| c=='E' || c=='I' || c=='O'|| c=='U')
        return true;
        return false;
    }
    bool isValid(string word) {
        if(word.size()<3)
        return false;
        bool check1=false;
        bool check2=false;
        for( auto it: word){
            if(it>='a' && it<='z'){
                if(vowel(it))
                check1=true;
                else
                check2=true;
            }
            else if(it>='A' && it<='Z'){
                if(vowel(it))
                check1=true;
                else
                check2=true;
            }
            else if(it>='0' && it<='9')
            continue;
            else{
                return false;
            }
        }
        return (check1 && check2);
    }
};