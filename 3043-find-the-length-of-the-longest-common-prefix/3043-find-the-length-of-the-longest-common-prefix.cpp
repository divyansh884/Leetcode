class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        map<int,bool> mp;
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            int num=0;
            for(int j=0;j<s.size();j++){
                num*=10;
                num+=(s[j]-'0');
                mp[num]=true;
            }
        }
        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            int num=0;
            for(int j=0;j<s.size();j++){
                num*=10;
                num+=(s[j]-'0');
                if(mp.find(num)!=mp.end())
                ans=max(ans,j+1);
            }
        }
        return ans;
    }
};