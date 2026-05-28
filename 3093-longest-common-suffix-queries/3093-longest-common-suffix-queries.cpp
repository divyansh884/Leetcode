class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int>ans;
        unordered_map<unsigned long long,int>mp;
        int minlenind=0;
        for(int i=0;i<wordsContainer.size();i++)
        {
            string s=wordsContainer[i];
            if(s.size() < wordsContainer[minlenind].size())
            minlenind = i;
            unsigned long long h = 0;
            unsigned long long power = 1;
            for (int j = s.size() - 1; j >= 0; j--)
            {
                h += (unsigned long long)(s[j] - 'a' + 1) * power;
                if (mp.find(h) == mp.end()) 
                {
                    mp[h] = i;
                }
                else 
                {
                    int ind = mp[h];
                    if (wordsContainer[ind].size() > s.size() ||
                       (wordsContainer[ind].size() == s.size() && i < ind)) 
                    {
                        mp[h] = i;
                    }
                }
                power *= 131;
            }
        }
        for(string s:wordsQuery)
        {
            unsigned long long h = 0;
            unsigned long long power = 1;
            int res = minlenind;
            for (int j = s.size() - 1; j >= 0; j--)
            {
                h += (unsigned long long)(s[j] - 'a' + 1) * power;
                if (mp.find(h) != mp.end())
                {
                    res = mp[h];
                }
                power *= 131;
            }
            ans.push_back(res);
        }
        return ans;
    }
};