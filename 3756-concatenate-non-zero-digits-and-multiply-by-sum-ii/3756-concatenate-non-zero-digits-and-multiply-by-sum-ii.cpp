class Solution {
public:
    const int mod = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> x(n);
        vector<long long> sum(n);
        vector<int> nz(n);
        
        x[0] = s[0] - '0';
        sum[0] = s[0] - '0';
        nz[0] = (s[0] != '0' ? 1 : 0);
        
        for (int i = 1; i < n; i++) {
            long long num = s[i] - '0';
            if (num != 0) {
                x[i] = (x[i - 1] * 10 + num) % mod;
                nz[i] = nz[i - 1] + 1;
            } else {
                x[i] = x[i - 1];
                nz[i] = nz[i - 1];
            }
            sum[i] = sum[i - 1] + num;
        }
        
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            long long num = x[r];
            if (l != 0) {
                long long left = x[l - 1];
                int k = nz[r] - nz[l - 1];
                long long sub = (left * power(10, k)) % mod;
                num = (x[r] - sub + mod) % mod;
            }
            
            long long mul = sum[r];
            if (l != 0) {
                mul = sum[r] - sum[l - 1];
            }
            
            long long ad = (num * (mul % mod)) % mod;
            ans.push_back(ad);
        }
        return ans;
    }
};