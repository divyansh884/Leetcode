class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, n = nums.size(), ans = 0,prev=-1;
        int j = 0;
        unordered_map<int, int> mp;
        vector<int> prefix(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                prefix[i] = nums[i];
            else
                prefix[i] = nums[i] + prefix[i - 1];
        }
        while (j < n) {
            if (mp.find(nums[j]) == mp.end()) {
                 sum += nums[j];
            } else {
                if(mp[nums[j]]>=prev){
                sum = prefix[j]-prefix[mp[nums[j]]];
                prev=mp[nums[j]]+1;
                }
                else{
                    sum += nums[j];
                }
            }ans = max(ans, sum);
            mp[nums[j]] = j;
            j++;
        }
        ans = max(ans, sum);
        return ans;
    }
};