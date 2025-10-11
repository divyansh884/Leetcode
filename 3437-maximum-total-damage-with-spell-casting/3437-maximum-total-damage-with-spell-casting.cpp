class Solution {
public:
    long long solve(map<int,int>& m, vector<int>& power, int idx,vector<long long >&dp) {
        if (idx == power.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long notTake = solve(m, power, idx + 1,dp);
        int next = idx + 1;
        while (next < power.size() && power[next] <= power[idx] + 2) next++;
        long long take = 1LL * power[idx] * m[power[idx]] + solve(m, power, next,dp);
        return dp[idx]=max(take, notTake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int> m;
        for (int x : power) m[x]++;
        vector<int> nums;
        for (auto &p : m) nums.push_back(p.first);
        vector<long long >dp(nums.size(),-1);
        return solve(m, nums, 0,dp);
    }
};