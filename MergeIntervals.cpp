#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:

    bool interval_Comparator(Interval i, Interval j) {
        return (i.start < j.start);
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), interval_Comparator);
        return intervals;
    }

};


int main(int argc, char *argv[])
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    s.merge(NULL);
    system("PAUSE");
    return 0;
}