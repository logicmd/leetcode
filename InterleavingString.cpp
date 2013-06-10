// TLE on large set
// DFS 存在死循环
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
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = s1.size();
        int n = s2.size();

        int l = s3.size();
        if(n+m != l) {
            return false;
        }

        if(m == 0) {
            return s2 == s3;
        }

        if(n == 0) {
            return s1 == s3;
        }

        bool **f = new bool*[m];
        for(int k = 0; k < m; k++) {
            f[k] = new bool[n];
        }
        f[0][0] = true;

        for (int i = 1; i < m+1; ++i)
        {
            f[i][0] = f[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        for (int j = 1; j < n+1; ++j)
        {
            f[0][j] = f[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                f[i][j] = (f[i-1][j] && (s1[i-1] == s3[i+j-1])) || (f[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }

        return f[m][n];
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