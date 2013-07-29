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
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool f=false;
        for(vector<int>::reverse_iterator it=digits.rbegin(); it!=digits.rend(); ++it) {
            if(it==digits.rbegin() || f) {
                (*it)++;
            }

            if((*it)>9) {
                *it = 0;
                f = true;
                //cout << "fuck " << endl;
                if(it+1==digits.rend()) {
                    digits.insert(digits.begin(),1);
                    //cout << "duck" << endl;
                    break;
                }
            } else {
                f = false;
            }
        }
        return digits;
    }
};


int main() {
    Solution s;
    vector<int> digits;
    digits.push_back(9);
    s.plusOne(digits);
    system("PAUSE");
    return 0;
}
