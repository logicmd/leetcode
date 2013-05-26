#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPrindrome(string s, int i, int j) {
        bool flag = true;
        while (i > j) {
            if(s[i] == s[j]) {
                continue;
            } else {
                flag = false;
                break;
            }
        }
        return flag;
    }

    void dfs(string s, int i, vector<string> &cur, vector<vector<string>> &set) {
        int n = s.size();

        if (i >= n)
        {
            return;
        }

        for(int j = i+1; j<n; ++j) {
            if(isPrindrome(s, i, j)) {
                cur.push_back(s.substr(i, j));
                if (j >= n) {
                    break;
                } else if (j == n-1)
                {
                    set.push_back(cur);
                }

                dfs(s, j+1, cur, set);
                cur.erase(--cur.end());
            }
        }


    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> set;
        vector<string> cur;

        dfs(s, 0, cur, set);
        return set;
    }
};