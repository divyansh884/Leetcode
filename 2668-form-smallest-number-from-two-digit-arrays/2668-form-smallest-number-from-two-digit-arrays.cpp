class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,bool> mp; 
        int num1=INT_MAX;
        int num2=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=true;
            num1=min(num1,nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]==true)
            ans.push_back(nums2[i]);
            num2=min(num2,nums2[i]);
        }
        ans.push_back(min(num1,num2)*10+max(num1,num2));
        int f=INT_MAX;
        for(int i=0;i<ans.size();i++){
            f=min(f,ans[i]);
        }
        return f;
    }
};