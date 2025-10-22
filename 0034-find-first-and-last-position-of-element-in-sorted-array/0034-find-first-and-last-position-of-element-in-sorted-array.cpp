class Solution {
public:
int bs1(vector<int>& arr,int &target){
    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(arr[mid]>target)
        high=mid-1;
        else if(arr[mid]<target)
        low=mid+1;
        else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
int bs2(vector<int> &arr,int &target){
    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(arr[mid]>target)
        high=mid-1;
        else if(arr[mid]<target)
        low=mid+1;
        else{
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        return {bs1(nums,target),bs2(nums,target)};
    }
};