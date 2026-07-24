class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,bool> mp,ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp=nums[i]^nums[j];
                mp[temp]=true;
            }
        }
        for(int i=0;i<n;i++){
            for(auto it: mp){
                int  temp2= it.first^nums[i];
                ans[temp2]=true;
            }
        }
        return ans.size();
    }
};