class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        map<pair<int, int>, int> mp;
        int d[] = {2, 4, 6};
        int cnt = 0;
        for (int i = 0; i < rs.size(); i++) {
            mp[{rs[i][0], rs[i][1]}]++;
        }
        map<int, int> mp1;
        for (int i = 0; i < rs.size(); i++) {
            int r = rs[i][0];
            int j = 0;
            if (mp1.find(r) != mp1.end()) {
                continue;
            }
            mp1[r]++;
            while (j < 3) {
                bool check = true;
                for (int k = 0; k < 4; k++) {
                    if (mp.find({r, d[j] + k}) != mp.end()) {
                        check = false;
                    }
                }
                if (check) {
                    cnt++;
                    j+=2;
                } else
                    j++;
            }
        }
        cnt += (n - mp1.size()) * 2;
        return cnt;
    }
};