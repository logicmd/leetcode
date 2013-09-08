class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        stack<node> st;
        int re=0;
        for(int i=0; i<s.size(); i++) {
            if(st.empty()) {
                st.push(node(s[i], i));
            } else {
                if(s[i]==')') {
                    node top = st.top();
                    if(top.c=='(') {
                        st.pop();
                        re=max(re, top.i-i+1);
                    } else {
                        st.push(node(s[i], i));                    }
                }


                if(dp[i]>max)
                    max=dp[i];
            }
        }
        return max;
    }
};