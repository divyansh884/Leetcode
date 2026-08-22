class Solution {
public:
    int minOperations(string s) {
        string temp = s;
        int cnt = 0;
        int ans = 1e9;

        for (int ind = 0; ind < s.size(); ind++) {
            int i = 0;
            int j = temp.size() - 1;

            int ta = cnt;

            while (i < j) {
                int tempi = temp[i] - 'a';
                int tempj = temp[j] - 'a';

                int st1 = abs(tempi - tempj);
                int st2 = (26 - max(tempi, tempj)) + min(tempi, tempj);

                ta += min(st1, st2);

                i++;
                j--;
            }

            ans = min(ans, ta);

            char cc = temp[0];

            temp.erase(temp.begin());
            temp.push_back(cc);

            cnt++;
        }

        int i = 0;
        int j = temp.size() - 1;

        int ta = cnt;

        while (i < j) {
            int tempi = temp[i] - 'a';
            int tempj = temp[j] - 'a';

            int st1 = abs(tempi - tempj);
            int st2 = (26 - max(tempi, tempj)) + min(tempi, tempj);

            ta += min(st1, st2);

            i++;
            j--;
        }

        ans = min(ans, ta);

        return ans;
    }
};