class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for( auto it: arr){
            mp[it]++;
        }
        int ans=-1;
        for( auto it: mp){
            if(it.first==it.second && it.first>ans)
            ans=it.first;
        }
        return ans;
    }
};