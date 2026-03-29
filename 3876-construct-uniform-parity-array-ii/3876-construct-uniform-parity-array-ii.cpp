class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int cnte = 0, cnto = 0, n = nums.size();
        int mine = INT_MAX, mino = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0){
                cnte++;
                mine=min(mine,nums[i]);
            }
            else{
                cnto++;
                mino=min(mino,nums[i]);
            }
        }
        if(cnte==n || cnto==n)
        return true;
        if(mine-mino<=0)
        return false;
        return true;
    }
};