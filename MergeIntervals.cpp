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
    // cpp 传参尽量传&
    static bool interval_Comparator(const Interval &i, const Interval &j) {
        return (i.start < j.start);
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() <= 1)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), interval_Comparator);
        for (vector<Interval>::iterator i = intervals.begin(); i != intervals.end(); ++i)
        {
            if (*(i+1).start > *(i).end)
            {
                continue;
            }
            if (*(i+1).start <= *(i).end && *(i+1).end >= *(i).start)
            {
                *(i).end = *(i+1).end;
                intervals.erase(i+1);
            } else {
                intervals.erase(i+1);
            }
        }
        return intervals;
    }

};


int main(int argc, char *argv[])
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    vector<Interval> i;
    s.merge(i);
    system("PAUSE");
    return 0;
}