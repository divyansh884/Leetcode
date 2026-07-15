class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;

        for (char ch : exp) {

            if (ch == ',')
                continue;

            if (ch != ')') {
                st.push(ch);
            } else {

                int cntt = 0, cntf = 0;

                while (st.top() != '(') {
                    if (st.top() == 't')
                        cntt++;
                    else
                        cntf++;
                    st.pop();
                }

                st.pop(); 

                char op = st.top();
                st.pop();

                if (op == '&') {
                    st.push(cntf ? 'f' : 't');
                }
                else if (op == '|') {
                    st.push(cntt ? 't' : 'f');
                }
                else {
                    st.push(cntt ? 'f' : 't');
                }
            }
        }

        return st.top() == 't';
    }
};