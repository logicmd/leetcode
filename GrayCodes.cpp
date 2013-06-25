#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <cstring>


using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        vector<int>().swap(ret);
        ret.push_back(0);
        if(n==0) {
            return ret;
        }

        vector<int> mask;
        vector<int>().swap(mask);
        for(int i=1; i<=(1<<n)-1; ++i) {
            int j=1;
            int ind = i;
            while(ind%2==0) {
                ind/=2;
                j<<=1;
            }
            mask.push_back(j);
        }

        // vector<int> mask = getMask(n);

        int code = 0;

        for(vector<int>::iterator it=mask.begin(); it!=mask.end(); ++it) {
            //cout << "mask: " << *it << "\t";
            code^=(*it);
            cout << code << endl;
            ret.push_back(code);
        }
        return ret;
    }

    // vector<int> getMask(int n) {
    //     vector<int> ret;
    //     vector<int>().swap(ret);
    //     for(int i=1; i<=(1<<n)-1; ++i) {
    //         int j=1;
    //         int ind = i;
    //         while(ind%2==0) {
    //             ind/=2;
    //             j<<=1;
    //         }
    //         ret.push_back(j);
    //     }
    //     return ret;
    // }


};

int main() {
    Solution s;
    s.grayCode(1);
    system("PAUSE");
}