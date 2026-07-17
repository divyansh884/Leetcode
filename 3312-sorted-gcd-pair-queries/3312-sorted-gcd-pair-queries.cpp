class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<int> ans;
        int max_num = 0;
        for (int num : nums) {
            max_num = max(max_num, num);
        }
        vector<long long> mp(max_num + 1, 0); 
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) {
                    mp[j]++; 
                    if (j != num / j) {
                        mp[num / j]++; 
                    }
                }
            }
        }
        vector<long long> gg(max_num + 1, 0);
        for (int i = max_num; i >= 1; i--) {
            gg[i] = (long long)mp[i] * (mp[i] - 1) / 2; 
            for (int j = 2 * i; j <= max_num; j += i) {
                gg[i] -= gg[j];
            }
        }
        vector<long long> pref(max_num + 1, 0);
        for (int i = 1; i <= max_num; i++) {
            pref[i] = pref[i - 1] + gg[i];
        }
        for (long long i = 0; i < queries.size(); i++) {
            long long temp = queries[i];
            int left = 1, right = max_num;
            int res = 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (pref[mid] > temp) {
                    res = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans.push_back(res);
        }      
        return ans;
    }
};