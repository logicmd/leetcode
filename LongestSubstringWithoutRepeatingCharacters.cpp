#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <stack>

// Google Interview 2 resemble

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n==0)
        {
            return 0;
        }
        int num = 0;
        int ret = 1;

        unordered_set<char> hm;
        for (int i = 0; i < n-1; ++i)
        {
            hm.clear();
            hm.insert(s[i]);
            num = 1;

            for (int j = i+1; j < n; ++j)
            {
                if (hm.find(s[j])==hm.end())
                {
                    hm.insert(s[j]);
                    num++;
                    if(num > ret)
                    {
                        ret = num;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return ret;
    }
};

int main()
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    cout << s.lengthOfLongestSubstring("hot");
    system("PAUSE");
    return 0;
}