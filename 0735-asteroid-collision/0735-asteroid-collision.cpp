class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if(asteroids[i]>0){
            st.push(asteroids[i]);
            continue;
            }
            while(!st.empty() && st.top()<abs(asteroids[i]) && st.top()>0)
            st.pop();
            if(st.empty() || st.top()<0)
            st.push(asteroids[i]);
            else if(st.top()==abs(asteroids[i]))
            st.pop();
        }
        vector<int> ans(st.size());
        while(!st.empty()){
            ans[st.size()-1]=st.top();
            st.pop();
        }
        return ans;
    }
};