class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,ans=0,n=s.size(),maxi=INT_MIN;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            maxi=max(maxi,mp[s[j]]);
            while((j-i+1)-maxi>k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};