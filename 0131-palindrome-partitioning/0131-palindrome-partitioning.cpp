class Solution {
public:

    bool pali(string &s){
        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[s.size()-1-i])
                return false;
        }
        return true;
    }

    void f(vector<vector<string>> &ans, string temp, vector<string> tt, int i, string &s){

        if(i == s.size()){
            if(temp == "")
                ans.push_back(tt);
            return;
        }

        temp.push_back(s[i]);
        if(pali(temp)){
            vector<string> tt2 = tt;
            tt2.push_back(temp);
            f(ans, "", tt2, i+1, s);
        }

        f(ans, temp, tt, i+1, s);
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        string temp = "";
        vector<string> tt;

        f(ans, temp, tt, 0, s);

        return ans;
    }
};