class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0;
        int a=0;
        int l=0;
        int o=0;
        int n=0;
        for(int i=0;i<text.size();i++){
            if(text[i]=='b')
            b++;
            else if(text[i]=='a')
            a++;
            else if(text[i]=='l')
            l++;
            else if(text[i]=='o')
            o++;
            else if(text[i]=='n')
            n++;
        }
        l= l/2;
        o=o/2;
        int m= min(min(b,a),min(l,o));
        return min(m,n);
    }
};