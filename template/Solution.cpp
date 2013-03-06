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
    Solution() {
        cout << "constructor" << endl;
    }
    void func() {
        cout << "hello world!" << endl;
    }
    ~Solution() {
        cout << "destructor" << endl;
    }
};


int main()
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    s.func();
    system("PAUSE");
    return 0;
}