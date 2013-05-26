// tle
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
    bool isPrindrome(string s, int i, int j, map<string, bool> &m) {
        map<string, bool>::iterator got = m.find(s.substr(i, j-i+1));
        if(got != m.end()) {
            return got->second;
        }


        bool flag = true;
        int i_copy = i;
        int j_copy = j;
        while (i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
                map<string, bool>::iterator _got = m.find(s.substr(i, j-i+1));
                if(_got != m.end()) {
                    return _got->second;
                }
            } else {
                flag = false;
                break;
            }
        }
        m.insert(make_pair(s.substr(i_copy, j_copy-i_copy+1), flag));
        return flag;
    }

    void dfs(string s, int i, vector<string> &cur, set<int> &st) {
        int n = s.size();

        map<string, bool> m;

        if (i >= n)
        {
            return;
        }

        for(int j = i; j<n; ++j) {
            if(isPrindrome(s, i, j, m)) {
                cur.push_back(s.substr(i, j-i+1));
                if (j == n-1) {
                    st.insert(cur.size());
                }

                dfs(s, j+1, cur, st);
                cur.erase(--cur.end());
            }
        }


    }

    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<int> st;
        vector<string> cur;


        //map<pair<int i, int j>, bool> m;
        //vector<vector<bool>> v;

        dfs(s, 0, cur, st);

        return *(st.begin())-1;
    }
};