class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxleft=0,maxright=0;
        int ans=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(maxleft<=height[left])
                maxleft=height[left];
                else{
                    ans+=maxleft-height[left];
                }
                left++;
            }
            else{
                if(maxright<=height[right])
                maxright=height[right];
                else{
                    ans+=maxright-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};