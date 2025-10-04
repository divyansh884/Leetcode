class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0,i=0;
        while(i<nums.size()){
            if(nums[i]==0){
            cnt++;
            nums.erase(nums.begin()+i);
            }
            else
            i++;
        }
        while(cnt!=0){
            nums.push_back(0);
            cnt--;
        }
        
    }
};