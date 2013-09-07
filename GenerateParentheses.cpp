struct pstr
{
    int l;
    int r;
    string s;
    pstr() {
        l=0; r=0;
        s="";
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        pstr *ps=new pstr();
        dfs(ps, n, ret);
        ret.resize(unique(ret.begin(), ret.end())-ret.begin());
        return ret;
    }

    void dfs(pstr *cur, int n, vector<string> &v) {
        if(cur->l+cur->r==2*n) {
            v.push_back(cur->s);
            return;
        }

        if(cur->l>cur->r || cur->l==n) {
            cur->s.insert(cur->s.end(), ')');
            cur->r++;
            dfs(cur, n, v);
            cur->s.erase((--cur->s.end()));
            cur->r--;
        }

        if(cur->l<n) {
            cur->s.insert(cur->s.end(), '(');
            cur->l++;
            dfs(cur, n, v);
            cur->s.erase((--cur->s.end()));
            cur->l--;
        }
    }
};

int main() {
    cout << 0xefffffff;
    cout << 0xffffffff;

}