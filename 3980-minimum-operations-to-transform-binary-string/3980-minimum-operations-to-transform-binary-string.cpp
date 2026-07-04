class Solution {
public:
    int minOperations(string s, string s2) {
        int n=s.size();
        if(n==1){
            if(s[0]==s2[0])
            return 0;
            else if(s[0]=='0' && s2[0]=='1') return 1;
            return -1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && s2[i] == '0') {
                if (i + 1 < n && s[i + 1] == '1') {
                    cnt++;
                    s[i] = '0';
                    s[i + 1] = '0';
                } else if (i + 1 < n && s[i + 1] == '0') {
                    cnt += 2;
                    s[i] = '0';
                    s[i + 1] = '0';
                } else if (i - 1>=0 && s[i - 1] == '1') {
                    cnt++;
                    s[i] = '0';
                    s[i - 1] = '0';
                }else if (i - 1 >=0  && s[i - 1] == '0') {
                    cnt += 2;
                    s[i] = '0';
                    s[i - 1] = '0';
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0' && s2[i]=='1'){
                cnt++;
                s[i]='1';
            }
        }
        return cnt;
    }
};