// MLE
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
typedef pair<set<point>, bool> pile;

class Solution {
//private:
    //vector<pile> vpile;
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

        //cout << m << " " << n << endl;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {

                if (board[i][j] == 'O')
                {
                    //cout << "hello" << endl;
                    pile p = add(board, i, j);
                    if (!p.first.empty() && !(p.second))
                    {
                        // vpile.push_back(p);
                        for (set<point>::iterator it = p.first.begin(); it != p.first.end(); ++it)
                        {
                            board[(*it).first][(*it).second] = 'X';
                        }
                    }
                }
            }
        }

        // for (vector<pile>::iterator i = vpile.begin(); i != vpile.end(); ++i)
        // {
        //     if ((*i).first.size() != 0 && !(*i).second)
        //     {
        //         for (set<point>::iterator p = (*i).first.begin(); p != (*i).first.end(); ++p)
        //         {
        //             board[(*p).first][(*p).second] = 'X';
        //         }
        //     }
        // }
    }

    pile add(vector<vector<char> > &board, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        set<point> pset;

        point pseed = make_pair(i, j);
        // for (vector<pile>::iterator it = vpile.begin(); it != vpile.end(); ++it)
        // {
        //     set<point> pset = (*it).first;
        //     if (pset.find(pseed) != pset.end())
        //     {
        //         return make_pair(pset, false);
        //     }
        // }


        stack<point> pool;
        bool isBound = false;

        pool.push(pseed);
        while(!pool.empty())
        {
            point seed = pool.top();
            pool.pop();
            pset.insert(seed);

            int x = seed.first;
            int y = seed.second;
            if (!isBound &&
                (x == 0 || x == m - 1 ||
                y == 0 || y == n - 1) )
            {
                isBound = true;
            }

            if (x - 1 >= 0 && board[x - 1][y] == 'O')
            {
                pool.push(make_pair(x - 1, y));
            }

            if (y - 1 >= 0 && board[x][y - 1] == 'O')
            {
                pool.push(make_pair(x, y - 1));
            }

            if (x + 1 < m && board[x + 1][y] == 'O')
            {
                pool.push(make_pair(x + 1, y));
            }

            if (y + 1 < n && board[x][y + 1] == 'O')
            {
                pool.push(make_pair(x, y + 1));
            }
        }

        return make_pair(pset, isBound);
    }
};

int main(int argc, char *argv[])
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    vector<char> v;
    v.push_back('X');
    vector<vector<char> > vv;
    vv.push_back(v);
    s.solve(vv);
    system("PAUSE");
    return 0;
}