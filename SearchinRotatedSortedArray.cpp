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
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(A, 0, n-1, target);
    }

    int dfs(int A[], int s, int e, int target) {
        if (s == e)
        {
            if (A[s] == target)
            {
                return s;
            }
            return -1;
        }
        if (s > e)
        {
            return -1;
        }
        int m = (s + e) / 2;
        if (target > A[m])
        {
            if (A[m] > A[s])
            {
                dfs(A, m, e, target);
            }
            else if (A[m] < A[s])
            {
                if (target > A[s])
                {
                    dfs(A, s, m, target);
                }
                else if (target < A[s])
                {
                    dfs(A, m, e, target);
                }
                else
                {
                    return s;
                }
            }
            else
            {
                if (target == A[s])
                {
                    return s;
                }
                if (target == A[e])
                {
                    return e;
                }
                return -1;
            }
        }
        else if (target < A[m])
        {
            if (A[m] > A[s])
            {
                if (target > A[s])
                {
                    dfs(A, s, m, target);
                }
                else if (target < A[s])
                {
                    dfs(A, m, e, target);
                }
                else
                {
                    return s;
                }
            }
            else if (A[m] < A[s])
            {
                dfs(A, m, e, target);
            }
            else
            {
                if (target == A[s])
                {
                    return s;
                }
                if (target == A[e])
                {
                    return e;
                }
                return -1;
            }
        }
        else
        {
            return m;
        }

    }
};


int main(int argc, char *argv[])
{

    Solution s;
    int a[] = {258,260,265,266,268,269,271,275,276,278,280,282,287,288,289,293,2,4,5,9,16,23,24,25,26,27,28,36,37,46,47,52,55,56,60,63,67,71,74,75,76,79,80,81,82,92,97,99,103,104,106,109,111,112,117,121,125,131,133,136,141,142,143,144,154,160,161,168,169,179,187,190,201,202,204,206,208,209,211,213,218,220,222,224,225,226,229,230,231,234,240,241,242,243,244,245,247,249,252,253,254,257};
    cout << s.search(a, 102, 81);
    system("PAUSE");
    return 0;
}


