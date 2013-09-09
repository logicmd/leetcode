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
    bool isPrindrome(string s, int i, int j, map< pair<int, int>, bool> &m) {
        map<pair<int, int>, bool>::iterator got = m.find(make_pair(i, j));
        if(got != m.end()) {
            return got->second;
        }


        bool flag = true;
        int i_copy = i;
        int j_copy = j;
        while (i <= j) {
            if(s[i] == s[j]) {

                map<pair<int, int>, bool>::iterator _got = m.find(make_pair(i, j));

                if(_got != m.end()) {
                    return _got->second;

                }
                i++;
                j--;
            } else {
                flag = false;
                break;
            }
        }
        m.insert(make_pair(make_pair(i_copy, j_copy), flag));
        return flag;
    }


    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        if(n<=1)    return 0;
        int *dp = new int[n];
        map<pair<int, int>, bool> m;
        dp[0]=1;
        for(int i=1; i<n; i++) {
            int min=2147483647;
            if(isPrindrome(s, 0, i, m)) {
                dp[i]=1;
                continue;
            }
            for(int j=0; j<i; j++) {
                if(isPrindrome(s, j+1, i, m)) {
                    if(1+dp[j]<min)
                        min = 1+dp[j];
                }
            }
            dp[i]=min;
        }


        return dp[n-1]-1;
    }
};