class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i]){
                    if(mp.find(j)==mp.end()){
                    mp[j]=fruits[i];
                    break;
                    }
                }
            }
        }
        return n-mp.size();
    }
};