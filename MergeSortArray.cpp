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
// reverse
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = m-1;
        int j = n-1;
        int k = i+j;
        while(i>=-1 && j>=-1 && k>=0) {
            while(i>=0 && ((j>=0 && A[i]>B[j]) || j==-1) ) {

                A[k] = A[i];
                i--;
                k--;
            }

            while(j>=0 && ((i>=0 && A[i]<=B[j]) || i==-1) ) {

                A[k] = B[j];
                j--;
                k--;
            }
        }
    }

};

int main() {
    Solution s;
    int A[] = {1,2,3, 0, 0, 0};
    int B[] = {2,5,6};
    int m = 6;
    int n = 3;
    cout << m << " " << n << endl;
    s.merge(A,m,B,n);
    for (int i=0; i<m; ++i) {
        cout << A[i]<<endl;
    }
    system("PAUSE");
    return 0;
}
