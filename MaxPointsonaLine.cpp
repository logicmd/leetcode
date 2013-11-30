#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0) {
            return 0;
        }


        int mmax=0;
        for(int i=0; i<points.size(); i++) {
            int maxk=0;
            int duplicate=0;
            int verticle=0;
            unordered_map<double, int> dict;
            unordered_map<double, int>().swap(dict);

            for(int j=0; j<points.size(); j++) {

                if(points[i].x==points[j].x) {
                    if(points[i].y==points[j].y) {
                        duplicate++;
                    } else {
                        verticle++;
                        if(verticle>maxk)
                            maxk=verticle;

                    }

                } else {
                    double kk = 1.0*(points[j].y-points[i].y)/(points[j].x-points[i].x);
                    dict[kk]++;
                    if(dict[kk]>maxk)
                        maxk=dict[kk];

                }
            }

            if(maxk+duplicate>mmax)
                mmax=maxk+duplicate;

        }

        return mmax;
    }

};

int main()
{
    //Solution* s = new Solution();
    //s->func();
    int i = 0;
    (i += i) > 0 ? i++ : i --;
    cout << i << endl;
    Solution s;
    system("PAUSE");
    return 0;
}