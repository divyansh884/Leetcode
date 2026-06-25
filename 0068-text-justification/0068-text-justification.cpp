class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> s;
        int n = words.size();
        string p = "";
        int temp = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int add = (temp != 0);
            if (temp + add + words[i].size() <= maxWidth) {
                if (add)
                    p += " ";
                p += words[i];
                cnt++;
                temp += add + words[i].size();
            } else {
                if (cnt == 1) {
                    while (p.size() < maxWidth)
                        p += ' ';
                    s.push_back(p);
                } else {
                    int addsp = cnt - 1;
                    int left = maxWidth - temp;
                    int pushie = left / addsp;
                    int addmore = left % addsp;
                    int pos = 0;
                    bool check = false;
                    int itr = 0;
                    while (itr != addsp && pos < p.size()) {
                        if (p[pos] != ' ') {
                            check = true;
                            pos++;
                        } else if (check) {
                            for (int j = 0; j < pushie; j++) {
                                p.insert(p.begin() + pos, ' ');
                                pos++;
                            }
                            if (addmore) {
                                p.insert(p.begin() + pos, ' ');
                                pos++;
                                addmore--;
                            }
                            check = false;
                            itr++;
                            pos++;
                        } else {
                            pos++;
                        }
                    }
                    s.push_back(p);
                }
                p = "";
                temp = 0;
                cnt = 0;
                i--;
            }
        }
        if (!p.empty()) {
            while (p.size() < maxWidth)
                p += ' ';
            s.push_back(p);
        }
        return s;
    }
};