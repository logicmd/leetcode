class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > re;
        vector<int> ccur;
        dfs(0, S, ccur, re);
        return re;
    }
    void dfs(int b, vector<int> &S, vector<int> &cur, vector<vector<int>> re) {
        re.push_back(cur);
        if(b >= S.size() ) {
            return;
        }
        for(int i=b; i<S.size(); i++) {
            vector<int> ccur(cur);
            ccur.push_back(S[i]);
            dfs(i+1, S, ccur, re);
        }
    }
};