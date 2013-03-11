// Google Interview 2 which I failed
// WTF!!! sigh

// Find longest substring which at most 2 distinct chars
// http://www.yiyome.com/article/view/1003377.html
// http://www.chingnotes.com/?p=353

#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <stack>

class Solution {
public:
    int lengthOfLongestSubstringAtMost2DisctinctChars(string s) {
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
                if (hm.find(s[j]) == hm.end())
                {
                    hm.insert(s[j]);
                }
                if (hm.size() <= 2)
                {
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
    cout << s.lengthOfLongestSubstringAtMost2DisctinctChars("hot");
    system("PAUSE");
    return 0;
}