class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> merged(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),merged.begin());
        if(merged.size()%2==0){
            return (merged.at(merged.size()/2)+merged.at((merged.size()/2)-1))/2;
        }
        else{
            return merged.at(((merged.size()+1)/2)-1);
        }
    }
};