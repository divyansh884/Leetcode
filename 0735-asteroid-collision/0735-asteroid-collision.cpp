class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> st;
        for (int i = 0; i < as.size(); i++) {
            if(st.empty())
            st.push(as[i]);
            else{
                if(as[i]>0)
                st.push(as[i]);
                else{
                while(!st.empty() && st.top()>0 && st.top()<abs(as[i]))
                st.pop();
                }
                if(st.empty() || st.top()<0)
                st.push(as[i]);
                if(as[i]<0 && st.top()==abs(as[i]))
                st.pop();
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};