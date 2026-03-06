class Solution {
public:
    int myAtoi(string s) {
         long long int ans=0;
        int i=0;
        bool checkn=false;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(i>=s.size())
        return ans;
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-')
        checkn=true;
        i++;
        }
        for(int j=i;j<s.size();j++){
            if(s[j]>='0' && s[j]<='9'){
                ans = ans*10 + (s[j]-'0');
                if(!checkn && ans>INT_MAX)
                return INT_MAX;
                if(checkn && ans*-1<INT_MIN)
                return INT_MIN;
            }
            else
            break;
        }
        if(checkn)
        ans=ans*-1;
        return ans;
    }
};