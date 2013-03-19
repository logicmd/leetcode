#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() == 0)
        {
            return 0;
        }
        int ret = 0;
        unordered_map<int, int> starts;
        unordered_map<int, int> ends;

        for (std::vector<int>::iterator i = num.begin(); i != num.end(); ++i)
        {
            int start_len;
            int end_len;

            bool extend_start = (starts.find(*i+1)==starts.end());
            bool extend_end = (starts.find(*i1)==starts.end());

            if (extend_start)
            {
                sd
            }

        }
        return ret;
    }
};

int main()
{
    Solution s;

    system("PAUSE");
    return 0;
}