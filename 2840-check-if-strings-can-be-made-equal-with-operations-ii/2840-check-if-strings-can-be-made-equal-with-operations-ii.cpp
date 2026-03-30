class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string eve1 = "";
        string eve2 = "";
        string odd1 = "";
        string odd2 = "";
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                eve1 += s1[i];
                eve2 += s2[i];
            } else {
                odd1 += s1[i];
                odd2 += s2[i];
            }
        }
        sort(eve1.begin(), eve1.end());
        sort(eve2.begin(), eve2.end());
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());
        return ((odd1 == odd2) && (eve1 == eve2));
    }
};