class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        if (nums1[0] % 2 != 0)
        return true;
        int cnto=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0)
            cnto++;
        }
        return cnto==0;
    }
};