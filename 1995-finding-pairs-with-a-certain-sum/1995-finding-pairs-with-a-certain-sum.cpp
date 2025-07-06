class FindSumPairs {
    unordered_map<int,int> num2;
    vector<int> num1,nums12;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto it: nums1)
        num1.push_back(it);
         for(auto it: nums2){
        num2[it]++;
        nums12.push_back(it);
        }
    }
    
    void add(int index, int val) {
      int ad=nums12[index];
      nums12[index]+=val;
      num2[ad+val]++;
      num2[ad]--;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto it: num1){
            int left=tot-it;
            if(left>=0){
                if(num2.find(left)!=num2.end())
                cnt+=num2[left];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */