#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
class NextPermutation {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 1) {
            return ;
        }
        vector<int>::iterator i = num.end();
        --i;

        for (; ; ) {
            vector<int>::iterator ii = i;
            --i;
            if (*i < *ii)
            {
                vector<int>::iterator j = num.end();
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