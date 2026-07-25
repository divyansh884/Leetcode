class Solution {
public:
    bool checkValidString(string s) {
        int l=0,r=0,star=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                l++;
            }
            if(s[i]==')'){
                r++;
            }
            if(s[i]=='*'){
                star++;
            }
            if(l+star<r){
                return 0;
            }
        }
        l=0;
        r=0;
        star=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                l++;
            }
            if(s[i]==')'){
                r++;
            }
            if(s[i]=='*'){
                star++;
            }
            if(l>r+star){
                return 0;
            }
        }
        if(l==r){
            return 1;
        }
        if(star && abs(l-r)<=star ){
            return 1;
        }
        else{
            return 0;
        }
        

    }
};