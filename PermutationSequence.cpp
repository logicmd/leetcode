#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
class PermutationSequence {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s;
        for (int i = 0; i < n; ++i)
        {
            s.push_back(i+'1');
        }
        k--;
        while(k--){
            nextPermutation(s);
        }
        return s;

    }
    void nextPermutation(string &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 1) {
            return ;
        }
        string::iterator i = num.end();
        --i;

        for (; ; ) {
            string::iterator ii = i;
            --i;
            if (*i < *ii)
            {
                string::iterator j = num.end();
                while(!(*i < *--j));

                swap(*i, *j);
                reverse(ii, num.end());
                return ;
            }

            if (i == num.begin())
            {
                reverse(num.begin(), num.end());
                return;
            }
        }
    }
};