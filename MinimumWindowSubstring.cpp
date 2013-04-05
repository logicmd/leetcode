// AC
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<char> hashset;
        for (int i = 0; i < T.size(); ++i)
        {
            hashset.insert(T[i]);
        }
    }
};

int main()
{
    Solution s;
    //int m[] = {100, 4, 200, 1, 3, 2};
    system("PAUSE");
    return 0;
}