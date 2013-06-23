#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <cstring>


using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n==0) {
            return 0;
        }

        int* ret = new int[n+1];
        //memset(ret, 0, sizeof(ret) * sizeof(int)); // random error
        for (int i = 0; i < n+1; ++i) {
            ret[i] = 0;
        }
        ret[0] = 1;
        int s0 = s[0] - '0';
        if(s0 >= 1 && s0 <= 9)
            ret[1] = 1;
        else
            ret[1] = 0;

        if(n > 1) {
            for(int i = 1; i < n; ++i) {
                int tmp = s[i] - '0';
                if (tmp >= 1 && tmp <= 9) {
                    ret[i+1] += ret[i];
                }
                tmp = (s[i-1] - '0') * 10 + s[i] - '0';
                if (tmp >= 10 && tmp <= 26) {
                    ret[i+1] += ret[i-1];
                }
            }
        }
        return ret[n];
    }


};

int main() {
    string s = "3";
    Solution sss;
    cout << sss.numDecodings(s) << endl;
    system("PAUSE");
}