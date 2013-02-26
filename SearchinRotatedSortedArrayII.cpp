// 这题被面过这个烂事我会随便乱说吗？
// WA for one
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
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(searchIndex(A, n, target) == -1) {
            return false;
        }
        return true;
    }

    int searchIndex(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = 0;
        int e = n - 1;

        while(s <= e) {
            int m = (s + e) / 2;
            int midVal = A[m];
            int startVal = A[s];
            int endVal = A[e];

            printf("A[%d]=%d,A[%d]=%d,A[%d]=%d\n", s,startVal,m,midVal,e,A[e]);

            if (target > midVal)
            {
                if (midVal > startVal)
                {
                    s = m + 1;
                }
                else if (midVal < startVal)
                {
                    if (target > startVal)
                    {
                        e = m - 1;
                    }
                    else if (target < startVal)
                    {
                        s = m + 1;
                    }
                    else
                    {
                        return s;
                    }
                }
                else
                {
                    if (s==m)
                    {
                        if (startVal == target)
                        {
                            return s;
                        }
                        if (endVal == target)
                        {
                            return e;
                        }
                        return -1;
                    }
                    if (midVal == endVal)
                    {
                        s++;
                        e--;
                    }
                    else
                    {
                        s = m + 1;
                    }
                }
            }
            else if (target < midVal)
            {
                if (midVal > startVal)
                {
                    if (target > startVal)
                    {
                        e = m - 1;
                    }
                    else if (target < startVal)
                    {
                        s = m + 1;
                    }
                    else
                    {
                        return s;
                    }
                }
                else if (midVal < startVal)
                {
                    e = m - 1;
                }
                else
                {
                    if (s==m)
                    {
                        if (startVal == target)
                        {
                            return s;
                        }
                        if (endVal == target)
                        {
                            return e;
                        }
                        return -1;
                    }
                    if (midVal == endVal)
                    {
                        s++; // Trick
                        e--;
                    }
                    else
                    {
                        s = m + 1; // 不管比他大还是比他小，都在剩下部分找
                    }
                }
            }
            else
            {
                return m;
            }

        }
        return -1;
    }

};


int main(int argc, char *argv[])
{

    Solution s;
    int a[] = {1,1,3,1};
    cout << s.search(a, 4, 3);
    system("PAUSE");
    return 0;
}


