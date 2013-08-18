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
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_a=0;
        for (int i=0; i<height.size(); ++i)
        {
            for (int j=i+1; j<height.size(); ++j)
            {
                int area=0;
                if(height[i]!=0&&height[j]!=0) {
                    int min_h=min(height[i],height[j]);
                    area=min_h*((j+1)*min_h/height[j]-(i+1)*min_h/height[i])/2;
                }
                if(area>max_a)  max_a=area;
            }

        }
        return max_a;
    }
};

int main() {
    Solution s;
    int h[]={0,1};
    vector<int> v(h, h+sizeof(h)/sizeof(int));
    cout << s.maxArea(v) << endl;
    return 0;
}