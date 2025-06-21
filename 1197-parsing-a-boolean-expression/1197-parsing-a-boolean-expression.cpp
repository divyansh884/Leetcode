class Solution {
public:
    bool parseBoolExpr(string expression) {
    string op="";
    stack<char> st;
    for(int i=0;i<expression.size();i++){
        if(expression[i]==',' || expression[i]=='(')
        continue;
        else if(expression[i]!=')'){
            st.push(expression[i]);
        }
        else{
            int tr=0,fal=0;
            while(!st.empty() && (st.top()=='t' || st.top()=='f')){
                if(st.top()=='t')
                tr++;
                else if(st.top()=='f')
                fal++;
                st.pop();
            }
            char cc=st.top();
            st.pop();
            char ans;
            if(cc=='&'){
                if(fal!=0)
                ans='f';
                else
                ans='t';
            }
            else if(cc=='|'){
                 if(tr!=0)
                ans='t';
                else
                ans='f';
            }
            else{
                if(tr!=0)
                ans='f';
                else
                ans='t';
            }
            st.push(ans);
        }
    }
    if(st.top()=='t')
    return true;
    return false;
    }
};