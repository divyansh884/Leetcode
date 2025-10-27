class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        int ss=0;
        int sum=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for( int j=0;j<m;j++){
                if(bank[i][j]=='1')
                cnt++;
            }
            sum+=(cnt*ss);
            if(cnt!=0)
            ss=cnt;
        }
        return sum;
    }
};