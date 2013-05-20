// AC
#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = board.size();
        if (m == 0)
        {
            return ;
        }
        int n = board[0].size();
        if (n == 0)
        {
            return ;
        }
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
            {
                expand(board, i, 0);
            }
            if (board[i][n-1] == 'O')
            {
                expand(board, i, n-1);
            }

        }

        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
            {
                expand(board, 0, j);
            }

            if (board[m-1][j] == 'O')
            {
                expand(board, m-1, j);
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == '-')
                {
                    board[i][j] = 'O';
                }
            }
        }

    }

    void expand(vector<vector<char> > &board, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        board[i][j] = '-';
        point pseed = make_pair(i, j);

        stack<point> pool;

        pool.push(pseed);
        while(!pool.empty())
        {
            point seed = pool.top();
            pool.pop();

            int x = seed.first;
            int y = seed.second;

            if (x - 1 >= 0 && board[x - 1][y] == 'O')
            {
                board[x - 1][y] = '-';
                pool.push(make_pair(x - 1, y));
            }

            if (y - 1 >= 0 && board[x][y - 1] == 'O')
            {
                board[x][y - 1] = '-';
                pool.push(make_pair(x, y - 1));
            }

            if (x + 1 < m && board[x + 1][y] == 'O')
            {
                board[x + 1][y] = '-';
                pool.push(make_pair(x + 1, y));
            }

            if (y + 1 < n && board[x][y + 1] == 'O')
            {
                board[x][y + 1] = '-';
                pool.push(make_pair(x, y + 1));
            }
        }

    }
};

int main()
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    vector<char> v;
    v.push_back('O');
    v.push_back('O');
    v.push_back('O');
    vector<vector<char> > vv;
    vv.push_back(v);
    vv.push_back(v);
    vv.push_back(v);
    s.solve(vv);
    system("PAUSE");
    return 0;
}