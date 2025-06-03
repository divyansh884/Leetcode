class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
        return 0;
        vector<int> primes(n+1,1);
        primes[0]=0;
        primes[1]=0;
        int cnt=0;
        for(int i=0;i*i<n;i++){
            if(primes[i]==1){
                for(int j=i*i;j<n;j+=i){
                    primes[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(primes[i]==1)
            cnt++;
        }
        return cnt;
    }
};