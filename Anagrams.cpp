#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        unordered_map<string, int> hash_map;
        for (vector<>::iterator i = strs.begin(); i != strs.end(); ++i)
        {
            set<char> s;
            string str;
            if (*i.size() > 0)
            {
                for (int j = 0; j < *i.size(); ++j)
                {
                    s.insert((*i)[j]);
                }
                for (set<char>::iterator j = s.begin(); j != s.end(); ++j)
                {
                    str.append(*j);
                }
            }

            if (hash_map.find(str) == end())
            {
                hash_map.emplace(str, 1);
            }
            else
            {
                hash_map.emplace(str, hash_map.find(str)->second + 1);
            }
        }

        for (vector<>::iterator i = strs.begin(); i != strs.end(); ++i)
        {
            set<char> s;
            if (*i.size() > 0)
            {
                for (int j = 0; j < *i.size(); ++j)
                {
                    s.insert((*i)[j]);
                }
            }

            if (hash_map.find(s)->second > 1)
            {
                hash_map.emplace(s, 1);
            }
            else
            {
                hash_map.emplace(s, hash_map.find(s)->second + 1);
            }
        }

        for (unordered_map<set<char>, int>::iterator i = hash_map.begin(); i != hash_map.end(); ++i)
        {
            if (i->second > 2)
            {

            }
        }
    }
};

int main()
{
    Solution s;

    system("PAUSE");
    return 0;
}