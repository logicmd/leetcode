class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0) {
            return 0;
        }
        string syn = NULL;
        set<string> st;
        set<string>().swap(st);
        int i = 0;
        dfs(s, i, syn, st);
        return st.size();
    }

    void dfs(string &s, int &i, string &syn, set<string> &st) {
        if(i >= s.size() - 1 ) {
            st.insert(syn);
        }
        if(s[i] == '1' || (s[i] == '2' && (i+1 < s.size()) && s[i+1] - '7' < 0)) {
            int trans = (s[i] - '0') * 10 + s[i+1] - '0';
            char c = 'A' + trans - 1;
            syn.push_back(c);
            i+=2;
            dfs(s, i, syn, st);
            i-=2;
            syn.erase(syn.end()-1);
        }
        char c = 'A' + s[i] - '1';
        syn.push_back(c);
        i++;
        dfs(s, i, syn, st);
        i--;
        syn.erase(syn.end()-1);
    }
};