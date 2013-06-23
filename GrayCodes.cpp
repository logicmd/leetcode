class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        vector<int>().swap(ret);
        if(n == 0) {
            return NULL;
        }
        if(n == 1) {
            ret.push_back(0);
            ret.push_back(1);
            return ret;
        }
        int *f = new int[n];
        f[0] = 1;
        for(int i=1; i<n)
    }
};

00
01    1
11    2
10    1


000
001   1
011   2
010   1
110   3
111
101
100



100   2
101   1
111   2
