#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;
typedef pair<set<point>, bool> pile;

class Solution {
private:
    vector<pile> vpile;
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = board.size();
        int n = board[0].size();


        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; i < n; ++j)
            {
                if (board[i][j] == 'o')
                {

                }
            }
        }
    }

    set<point> add(vector<vector<char>> &board, int i, int j) {
        for (std::vector<pile>::iterator i = .begin(); i != .end(); ++i)
        {
            *(i).first.
        }
    }
};

int main(int argc, char *argv[])
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    s.func();
    system("PAUSE");
    return 0;
}