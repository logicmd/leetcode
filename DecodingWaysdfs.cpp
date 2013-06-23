#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>


using namespace std;

// TLE dfs

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


        if(s.size()==0) {
            return 0;
        }
        string syn = "";

        int num = 0;

        unsigned int i = 0;
        dfs(s, i, syn, num);
        return num;
    }

    void dfs(string &s, unsigned int &i, string &syn, int &num) {
        if(i >= s.size() ) {
            num++;
            return;
        }

        if(i+1 < s.size() && ( (s[i] == '1') || (s[i] == '2'  && s[i+1] - '7' < 0) ) ) {
            int trans = (s[i] - '0') * 10 + s[i+1] - '0';
            char c = 'A' + trans - 1;
            syn.push_back(c);
            i+=2;
            dfs(s, i, syn, num);
            i-=2;
            syn.erase(syn.end()-1);
        }
        if(s[i] == '0') {
            return;
        }
        char c = 'A' + s[i] - '1';
        syn.push_back(c);

        i++;
        dfs(s, i, syn, num);
        i--;
        syn.erase(syn.end()-1);
    }
};

int main() {
    string s = "0";
    Solution sss;
    cout << sss.numDecodings(s) << endl;
    system("PAUSE");
}