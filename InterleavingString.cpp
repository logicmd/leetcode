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

    bool dfs(int i, int j, int k) {
        if ((i == str1.size() - 1) && (j == str2.size() - 1) && (k == str.size() - 1))
        {
            return true;
        }

        if (str[k] == str1[i])
        {
            k++;
            i++;
            dfs(i, j, k);
            i--;
            k--;
        }
        if (str[k] == str2[j]) {
            k++;
            j++;
            dfs(i, j, k);
            j--;
            k--;
        }
        return false;
    }

};


int main(int argc, char *argv[])
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    cout << s.isInterleave("a","b","ab");
    system("PAUSE");
    return 0;
}