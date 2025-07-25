class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string last = ans.back();
            if (folder[i].substr(0, last.size()) == last &&
                (folder[i].size() == last.size() || folder[i][last.size()] == '/')) {
                continue;
            }
            ans.push_back(folder[i]);
        }

        return ans;
    }
};
