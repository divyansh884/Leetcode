class Solution {
public:
    int maximumGain(string s, int x, int y) {
    string r;
    int ans=0;
    stack<char> st;
    stack<char> sl;
    st.push(s[0]);
    if(x>=y){
    for(int i=1;i<s.size();i++){
        if(st.size()==0)
        st.push(s[i]);
        if(st.top()=='a' && s[i]=='b'){
            st.pop();
            ans+=x;
        }
        else
        st.push(s[i]);
    }
    while(st.size()!=0){
        char m=st.top(); 
        if(sl.size()==0){
        sl.push(m);
        st.pop();
        }
        else if(sl.top()=='a' && m=='b'){
            sl.pop();
            st.pop();
            ans+=y;
        }
        else{
            st.pop();
            sl.push(m);
        }
    }
    }
    else{
        for(int i=1;i<s.size();i++){
        if(st.size()==0)
        st.push(s[i]);
        else if(st.top()=='b' && s[i]=='a' && st.size()!=0){
            st.pop();
            ans+=y;
        }
        else
        st.push(s[i]);
    }
    while(st.size()!=0){
        char m=st.top(); 
        if(sl.size()==0){
        sl.push(m);
        st.pop();
        }
        else if(sl.top()=='b' && m=='a'){
            sl.pop();
            st.pop();
            ans+=x;
        }
        else{
            st.pop();
            sl.push(m);
        }
    }
    }
    return ans;
    }
};