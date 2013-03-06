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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = start.size();

        int times = 0;

        stack<string> st;
        st.push(start);
        while (!st.empty())
        {
            vector<string> s;
            s.clear();

            int cout = 0;
            while (!st.empty())
            {
                s.push_back(st.top());
                st.pop();
                cout++;
            }
            if (cout>0)
            {
                times++;
            }

            if (!dict.empty())
            {
                for (vector<string>::iterator i = s.begin(); i != s.end(); ++i)
                {
                    for (unordered_set<string>::iterator j = dict.begin(); j != dict.end();)
                    {
                        if (isConnect(*i, *j, n))
                        {

                            if (isConnect(*j, end, n))
                            {
                                return ++times;
                            }
                            st.push(*j);
                            dict.erase(j++);
                        }
                        else
                        {
                            ++j;
                        }
                    }
                }
            }
            else
            {
                for (vector<string>::iterator i = s.begin(); i != s.end(); ++i)
                {
                    if (isConnect(*i, end, n))
                    {
                        return times;
                    }
                }
                return 0;
            }
        }
        return 0;


    }

    bool isConnect(string s, string e, int n) {
        int c = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != e[i])
            {
                c++;
                if (c > 1)
                {
                    return false;
                }
            }
        }
        return c==1 || c==0;
    }
};

int main()
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    s.ladderLength("hot", "dot", dict);
    system("PAUSE");
    return 0;
}