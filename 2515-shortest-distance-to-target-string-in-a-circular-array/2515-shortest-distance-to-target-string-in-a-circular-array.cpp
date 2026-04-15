class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int cnt1 = 0, cnt2 = 0, n = words.size();
        int i = startIndex;
        bool check1 = false;
        bool check2 = false;
        while (true) {
            if (words[i] == target) {
                check1 = true;
                break;
            } else {
                i = (i + 1) % n;
                cnt1++;
            }
            if (i == startIndex)
                break;
        }
        i = startIndex;
        while (true) {
            if (words[i] == target) {
                check2 = true;
                break;
            } else {
                i = (i - 1 + n) % n;
                cnt2++;
            }
            if (i == startIndex)
                break;
        }
        if (check1 && check2)
            return min(cnt1, cnt2);
        if (check1)
            return cnt1;
        if (check2)
            return cnt2;
        return -1;
    }
};