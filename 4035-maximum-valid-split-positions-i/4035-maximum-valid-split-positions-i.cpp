class Solution {
public:
    int check(vector<int>nums){
        int count = 0;
        int n = nums.size();
        vector<int>gcdleft(n);
        vector<int>gcdright(n);

        gcdleft[0]=nums[0];
        for(int i=1;i<n;i++){
            gcdleft[i] = gcd(gcdleft[i-1],nums[i]);
        }

        gcdright[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            gcdright[i] = gcd(gcdright[i+1],nums[i]);
        }

        for(int i=0;i<n-1;i++){
            int gcdleftval = gcdleft[i];
            int gcdrightval = gcdright[i+1];
            if(gcdleftval==gcdrightval){
                count++;
            }
        }
        return count;
    }
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int val = check(nums);
        count = max(val,count);
        for(int i=0;i<n;i++){
            vector<int> curr;
            for(int j=0;j<n;j++){
                if(i!=j) curr.push_back(nums[j]);
            }
            int val1 = check(curr);
            count = max(val1,count);
        }
        return count;
    }
};