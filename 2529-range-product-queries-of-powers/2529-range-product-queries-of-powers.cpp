class Solution {
    int MOD=1000000007;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                powers.push_back(1LL<<i);
            }
        }
        vector<int> ans;
        for(int i = 0; i<queries.size(); i++){
            int p = 1;
            for(int j = queries[i][0]; j<=queries[i][1]; j++){
                p = ((long long)p*powers[j])%MOD;
            }
            ans.push_back(p);
        }
        return ans;
    }
};