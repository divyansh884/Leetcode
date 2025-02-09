class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posi;
        vector<int> negi;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
            negi.push_back(nums[i]);
            else
            posi.push_back(nums[i]);
        }
        int s=0,e=0;
            for(int i=0;i<n;i++){
                if(i%2==0){
                ans.push_back(posi[s]);
                s++;
                }
                else{
                    ans.push_back(negi[e]);
                    e++;
                }
            }
        return ans;
    }
};