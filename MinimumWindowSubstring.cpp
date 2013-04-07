// AC
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
#include <multiset>
#include <multimap>
#include <stack>

using namespace std;
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        multiset<char> hashset;
        multimap<char, int> hashmap;
        int n = T.size();
        if (n == 0)
        {
            return "";
        }
        for (int i = 0; i < n; ++i)
        {
            hashset.insert(T[i]);
        }

        int s = S.size() - 1, e = 0;
        if (s == -1)
        {
            return "";
        }
        for (int i = 0; i < S.size(); ++i)
        {
            if (hashset.find(S[i]) != hashset.end())
            {
                hashmap.insert(make_pair(S[i], i));
            }
            if (hashmap.size() == n)
            {
                int min = S.size();
                int max = -1;
                for (multimap<char, int>::iterator j = hashmap.begin(); j != hashmap.end(); ++j)
                {
                    if (j->second > max)
                    {
                        max = j->second;
                    }
                    if (j->second < min)
                    {
                        min = j->second;
                    }
                }

                if (max - min > 0 && max - min <= S.size() - 1 && max - min < e - s)
                {
                    e = max;
                    s = min;
                }
            }
        }
        if (s <= e)
        {
            return S.substr(s, e-s+1);
        }
        return "";



    }
};

int main()
{
    Solution s;
    //int m[] = {100, 4, 200, 1, 3, 2};
    system("PAUSE");
    return 0;
}