// TLE on large set
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;


class Solution {
public:
    string str1, str2, str;
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        str1 = s1;
        str2 = s2;
        str = s3;
        return dfs(0,0,0);
    }

    bool dfs(unsigned int i, unsigned int j, unsigned int k) {
        //cout << i << " " << j << " " << k << endl;
        //cout << "fuck  " << str1.size() << " " << str2.size() << " " << str.size() << endl;
        if ((i == str1.size()) && (j == str2.size()) && (k == str.size()))
        {
            //cout << "fuck 2  " << str1.size() << " " << str2.size() << " " << str.size() << endl;
            return true;
        }

        if (str[k] == str1[i])
        {
            k++;
            i++;
            if (dfs(i, j, k)) {
                return true;
            }
            i--;
            k--;


        }
        if (str[k] == str2[j]) {
            k++;
            j++;
            if (dfs(i, j, k)) {
                return true;
            }
            j--;
            k--;
        }
        return false;
    }

};


int main()
{
    Solution s;
    string f;
    if (s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa","babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab","babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"))
    {
        f = "yes";
    }
    else
    {
        f = "no";
    }
    cout << f << endl;
    system("PAUSE");
    return 0;
}