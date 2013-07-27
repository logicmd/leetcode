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
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size()==0 || matrix[0].size()==0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int ret = 0;
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ret < getCurMax(i, j, matrix, m, n)) {
                    ret = getCurMax(i, j, matrix, m, n);
                }
            }
        }
    }
    int getCurMax(int i, int j, vector<vector<char> > &mat, int m, int n) {
        if((i-1>=0 && mat[i-1][j]==1) || (j-1>=0 && mat[i][j-1]==1)) {
            return 0;
        }
        int width = 1, height = 1;
        int re = 0;

        for(int j_run = j+1; j_run<m && mat[i][j_run]==1; ) {
            j_run++;
            width++;
            re = width * height;
        }

        for(int i_run = i+1; i_run<n; ) {
            if(mat[i_run][j] == 0) {
                break;
            }
            for(int j_run = j; j_run<j+width;) {
                if(mat[i_run][j_run]==0) {
                    width = j_run - j;
                    if (re < width * (i_run-i+1)) {
                        re = width * (i_run-i+1);
                    }
                    break;
                }
            }
        }

        return re;
    }
};