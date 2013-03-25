// AC
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

        for (vector<int>::iterator i = num.begin(); i != num.end(); ++i)
        {
            int start_len = 0;
            int end_len = 0;

            unordered_map<int, int>::iterator start_find = starts.find(*i+1);
            unordered_map<int, int>::iterator end_find = ends.find(*i-1);

            bool extends_start = (start_find != starts.end());
            bool extends_end = (end_find != ends.end());

            if (extends_start && extends_end)
            {
                start_len = start_find->second;
                end_len = end_find->second;

                //ends.erase(*i+1);
                //ends.erase(*i-1);
                //starts.erase(*i-1);
                //starts.erase(*i+1);

                int start = *i - end_len;
                int new_len = start_len + end_len + 1;
                // caused by duplicated entry
                if (new_len > starts[start] && new_len > ends[start + new_len - 1])
                {
                    starts[start] = new_len;
                    ends[start + new_len - 1] = new_len;
                }

            }
            else if (extends_start)
            {
                start_len = start_find->second;

                starts.erase(*i + 1);

                int new_len = start_len + 1;
                // caused by duplicated entry
                if (new_len > starts[*i] && new_len > ends[*i - new_len + 1])
                {
                    starts[*i] = new_len;
                    ends[*i + new_len - 1] = new_len;
                }


            }
            else if (extends_end)
            {

                end_len = end_find->second;

                ends.erase(*i - 1);

                int new_len = end_len + 1;
                // caused by duplicated entry
                if (new_len > ends[*i] && new_len > starts[*i - new_len + 1])
                {
                    ends[*i] = new_len;
                    starts[*i - new_len + 1] = new_len;
                }

            }
            else
            {
                // caused by duplicated entry
                if(starts.find(*i)==starts.end() && ends.find(*i)==ends.end()) {
                    starts.emplace(*i, 1);
                    ends.emplace(*i, 1);
                }
            }

        }

        for (unordered_map<int, int>::iterator i = starts.begin(); i != starts.end(); ++i)
        {
            cout << "start: " << i->first << "; length: " << i->second << endl;
            if (i->second > ret)
            {
                ret = i->second;
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    int m[] = {-9,-4,9,-7,0,7,3,-1,6,2,-2,8,-2,0,2,-7,-5,-2,6,-5,0,-8,8,1,0,6,8,-8,-1};
    //int m[] = {100, 4, 200, 1, 3, 2};
    vector<int> v (m, m+sizeof(m)/sizeof(int));
    s.longestConsecutive(v);
    system("PAUSE");
    return 0;
}