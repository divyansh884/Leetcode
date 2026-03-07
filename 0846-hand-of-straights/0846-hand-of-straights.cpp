class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        vector<int> grp(groupSize, -1);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(hand[i]);
        }
        while (pq.empty()) {
            auto it = find(grp.begin(), grp.end(), pq.top() - 1);
            if (it != grp.end()) {
                grp[it - grp.begin()] = pq.top();
            } else {
                auto it1 = find(grp.begin(), grp.end(), - 1);
                if (it1 != grp.end()) {
                    grp[it1 - grp.begin()] = pq.top();
                }else{
                    return false;
                }
            }
            pq.pop();
        }
        return true;
    }
};