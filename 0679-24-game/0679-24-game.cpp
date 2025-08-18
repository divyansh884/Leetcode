class Solution {
public:
    bool check(vector<double>& cards) {
        if (cards.size() == 1) {
            return fabs(cards[0] - 24) < 1e-6;
        }

        int n = cards.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(cards[k]);
                }
                for (int op = 0; op < 4; op++) {
                    if (op == 0) next.push_back(cards[i] + cards[j]);
                    if (op == 1) next.push_back(cards[i] - cards[j]);
                    if (op == 2) next.push_back(cards[i] * cards[j]);
                    if (op == 3) {
                        next.push_back(cards[i] / cards[j]);
                    }

                    if (check(next)) return true;
                    next.pop_back(); 
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return check(nums);
    }
};
