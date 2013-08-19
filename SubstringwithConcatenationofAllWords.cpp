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
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> pos;
        if(S=="" || L.size()==0)    return pos;
        int n=L[0].size();
        int m=L.size();
        // S.size() is a unsigned int, fuck
        int s_size=S.size();

        if(s_size-m*n==0) {
            vector<string> s;
            for(int i=0; i<m; ++i) {
                s.push_back(S.substr(n*i,n));
            }
            if(isMatched(s,L))
                pos.push_back(0);
            return pos;
        }

        for(int i=0; i<s_size-m*n; ++i) {
            vector<string> s;
            for(int j=0; j<m; j++) {
                s.push_back(S.substr(i+n*j,n));
            }
            if(isMatched(s,L))
                pos.push_back(i);
        }
        return pos;

    }

    bool isMatched(vector<string> s, vector<string> t) {
        int m=t.size();
        for(int i=0; i<s.size(); ++i) {
            for(vector<string>::iterator its=t.begin(); its!=t.end(); ++its) {
                if(s[i]==(*its)) {
                    t.erase(its);
                    break;
                }
            }
            if(t.size()==m-1) {
                m=t.size();
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution s;
    string S="a";
    vector<string> L;
    L.push_back("a"); L.push_back("a");
    s.findSubstring(S,L);
    return 0;
}