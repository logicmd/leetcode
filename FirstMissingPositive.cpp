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
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0)    return 1;
        for(int i=0; i<n; i++) {
            if(A[i]<=0)
                A[i]=n+2;
        }
        for(int i=0; i<n; i++) {
            int absi=abs(A[i]);
            if(absi<=n)
                A[absi-1]=-abs(A[absi-1]);
        }
        for(int i=0; i<n; i++) {
            if(A[i]>0)
                return i+1;
        }

        return n+1;
    }
};

int main() {
    Solution s;
    int A[]={3,4,-1,1};
    cout << s.firstMissingPositive(A, 4) << endl;
    return 0;
}