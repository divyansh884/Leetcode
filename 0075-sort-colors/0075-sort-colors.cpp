class Solution {
public:
    void sortColors(vector<int>& nums) {
        int NO0=0,NO1=0,NO2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) NO0++;
            if(nums[i]==1) NO1++;
            if(nums[i]==2) NO2++;


        }

        for(int i=0;i<NO0;i++){
            nums[i]=0;
        }

         for(int i=NO0;i<NO0+NO1;i++){
            nums[i]=1;
        }

         for(int i=NO0+NO1;i<n;i++){
            nums[i]=2;
        }
    }
};