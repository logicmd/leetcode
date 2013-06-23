class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l=0;
        for(int i=0; i<s.size(); ) {
            int longestl = 1;
            stack<char> st;
            while (!st.empty()) st.pop();
            //stack<char>().swap(st);
            for(int j=2; i+j-1<s.size(); j+=2) {
                if(is_valid(s.substr(i,j), j-2, st)) {
                    longestl = j;
                    if(j>l) {
                        l = j;
                    }
                }
            }
            i+=longestl;
        }
        return l;
    }

    bool is_valid_e(string s, int k, stack<char> &st) {
        for(int i=k; i<s.size(); ++i) {
            if( s[i] == ')' ) {
                if (!st.empty() && st.top() == '(' ) {
                   st.pop();
                } else if (st.empty()) {
                    return false;
                }
            } else {
                st.push('(');
            }
        }
        return st.empty();
    }

    bool is_valid(string s, int k, stack<char> &st) {
        for (int i=k; i<s.size(); ++i) {
            if ( !st.empty() && s[i] == ')' &&  st.top() == '(' ) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }


    bool is_valid(string s, stack<char> &st) {
        for (int i=0; i<s.size(); ++i) {
            if ( !st.empty() && s[i] == get_pair(st.top()) ) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }

    char get_pair(char c) {
        switch(c) {
            case '{':
                return '}';
            case '(':
                return ')';
            case '[':
                return ']';
            default:
                return ' ';
        }
    }
};