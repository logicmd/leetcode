class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        int n=num.size();

        if (n<=1) {
            ret.push_back(num);
            return ret;
        }

        bool *f=new bool[n];
        for(int i=0; i<n; i++) {
            f[i]=true;
        }

        vector<int> cur;

        dfs(n, cur, ret, f, num);

        return ret;
    }


    void dfs(int n, vector<int> &cur, vector<vector<int> > &res, bool f[], vector<int> &num) {
        if(cur.size()>=n) {
            res.push_back(cur);
            return;
        }

        for(int i=0; i<n; i++) {
            if(f[i]) {
                f[i]=false;
                cur.push_back(num[i]);
                dfs(n, cur, res, f, num);
                cur.pop_back();
                f[i]=true;
            }
        }
    }
};