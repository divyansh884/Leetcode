class Solution {
public:
    bool checkIPV4(vector<string>& ans) {
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].size() == 0 || ans[i].size() > 3)
                return false;
            if (ans[i][0] == '0' && ans[i].size() > 1)
                return false;
            int re = 0;
            for (int j = 0; j < ans[i].size(); j++) {
                if (ans[i][j] >= '0' && ans[i][j] <= '9') {
                    re = re * 10 + (ans[i][j] - '0');
                } else
                    return false;
            }
            if (re > 255)
                return false;
        }
        return true;
    }
    bool checkIPV6(vector<string>& ans) {
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].size() == 0 || ans[i].size() > 4)
                return false;
            for (int j = 0; j < ans[i].size(); j++) {
                if (ans[i][j] >= '0' && ans[i][j] <= '9')
                    continue;
                else if (ans[i][j] >= 'a' && ans[i][j] <= 'f')
                    continue;
                else if (ans[i][j] >= 'A' && ans[i][j] <= 'F')
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
    string validIPAddress(string queryIP) {
        vector<string> keep;
        string ans = "";
        bool check1=false;
        bool check2=false;
        for (int i = 0; i < queryIP.size(); i++) {
             if (queryIP[i] == ':') {
                check1=true;
            }
            else if (queryIP[i] == '.' ){
                check2=true;
            }
        }
        if(check1 && check2)
        return "Neither";
        for (int i = 0; i < queryIP.size(); i++) {
            if (queryIP[i] == ':' || queryIP[i] == '.') {
                keep.push_back(ans);
                ans = "";
            } else
                ans += queryIP[i];
        }
        keep.push_back(ans);
        if (keep.size() != 8 && keep.size() != 4)
            return "Neither";
        if (keep.size() == 4 && checkIPV4(keep))
            return "IPv4";
        if (keep.size() == 8 && checkIPV6(keep))
            return "IPv6";
        return "Neither";
    }
};