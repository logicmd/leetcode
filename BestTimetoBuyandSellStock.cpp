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
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=prices.size();
        if(n==0 || n==1)    return 0;
        int min = (1<<30 - 1)+1<<30; // 坑
        int max = -1<<31;

        int re=0;

        for(int i=0; i<n; i++) {
            if(prices[i]<min) {
                min=prices[i];
                max=0;
            }

            if(prices[i]>max) {
                max=prices[i];
            }


            if(max-min>re) {
                re=max-min;
            }


        }

        return re;

    }
};



int main()
{
    Solution s;
    int a[] = {1,2};
    vector<int> v(a, a+2);
    cout << s.maxProfit(v);

    system("PAUSE");
    return 0;
}