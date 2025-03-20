class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
             unordered_map<char,int> mp;
            for(int j=i;j<s.size();j++){
            mp[s[j]]++;
                 int leastFrequent = INT_MAX;
                int mostFrequent = INT_MIN;
                for (auto it : mp) {
                    leastFrequent = min(leastFrequent, it.second);
                    mostFrequent = max(mostFrequent, it.second);
                }
                sum += mostFrequent - leastFrequent;
            }
        }
        return sum;
    }
};