class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int ind1=i,ind2=-1,ind3=-1;
            for(int j=i+1;j<n;j++){
                if(nums[j]==num && ind2==-1)
                ind2=j;
                else if(nums[j]==num && ind3==-1)
                ind3=j;
                if(ind2!=-1 && ind3!=-1)
                break;
            }
            if(ans==-1 && ind2!=-1 && ind3!=-1)
            ans=abs(ind1-ind2)+abs(ind2-ind3)+abs(ind3-ind1);
            else if(ans!=-1 && ind2!=-1 && ind3!=-1)
            ans= min(ans,abs(ind1-ind2)+abs(ind2-ind3)+abs(ind3-ind1));

        }
        return ans;
    }
};