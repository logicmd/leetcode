class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++) {
            if(tokens[i]=="+") {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2+op1);
            }
            else if(tokens[i]=="-") {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2-op1);
            }
            else if(tokens[i]=="*") {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2*op1);
            }
            else if(tokens[i]=="/") {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2/op1);
            }
            else {
                st.push(atoi(tokens[i]));
            }
        }
        return st.top();

    }



};