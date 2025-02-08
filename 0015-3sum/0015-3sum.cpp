class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> ans1;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        unordered_map<int,int> mp;
        unordered_map<int,bool> mp1;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i+1;
        }
        for(int i=0;i<n;i++){
            int low = i+1, high = n-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    ans.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }
        for(auto it: ans)
        ans1.push_back(it);
        return ans1;
    }
};