class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> st0;
        stack<int> st1;
        int n = s.size();
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if ((s[i] == ')' || s[i] == '(') && locked[i] == '0') {
                st0.push(i);
            } else {
                if(s[i]=='('){
                    st1.push(i);
                }
                else{
                    if(!st1.empty())
                    st1.pop();
                    else if(!st0.empty())
                    st0.pop();
                    else{
                        ans= false;
                        break;
                    }
                }
            }

        }
        while(!st0.empty() && !st1.empty() && st1.top()<st0.top()){
            st0.pop();
            st1.pop();
        }
        if(!st1.empty())
        ans=false;
        if(st0.size()%2!=0)
        ans=false;
        return ans;
    }
};