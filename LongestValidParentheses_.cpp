struct node
{
    char c;
    int i;
    node(char cc, int ii) {
        c=cc;
        i=ii;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<node> st;
        int re;
        for(int i=0; i<s.size(); i++) {
            if(st.empty() && s[i] == '(') {
                st.push(node(s[i], i));
            } else {
                if(s[i]==')') {
                    node top = st.front();
                    if(top.c=='(') {
                        st.pop();
                        re=max(re, top.i-i+1);
                    } else {
                        st.push(node(s[i], i));
                    }
                }
            }
        }
        return re;
    }
};