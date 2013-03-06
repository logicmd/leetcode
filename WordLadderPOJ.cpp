#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
#include <set>
#include <stack>
#define N 6003
using namespace std;
class Solution {
public:
    int ladderLength(string start, string end, vector<string> &dict) {
        int max_neg = ~(1 << 31);
        int all_ones = -1;
        const int MAX = all_ones & max_neg;

        int k = start.size();
        int n = dict.size();
        // start - 0 dict 1 ~ n end - n+1
        int dis[N][N];
        memset(dis, sizeof(dis), 0);
        for (int i = 1; i <= n; ++i)
        {
            if (isConnect(start, dict[i-1], k))
            {
                dis[0][i] = 1;
                dis[i][0] = 1;
            }
            else
            {
                dis[0][i] = MAX;
                dis[i][0] = MAX;
            }
        }

        for (int i = 1; i <= n-1; ++i)
        {
            for (int j = i+1; j <= n; ++j)
            {
                if (isConnect(dict[i-1], dict[j-1], k))
                {
                    dis[i][j] = 1;
                    dis[j][i] = 1;
                }
                else
                {
                    dis[i][j] = MAX;
                    dis[j][i] = MAX;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (isConnect(dict[i-1], end, k))
            {
                dis[i][n+1] = 1;
                dis[n+1][i] = 1;
            }
            else
            {
                dis[i][n+1] = MAX;
                dis[n+1][i] = MAX;
            }
        }


    }

    bool isConnect(string s, string e, int k) {
        int c = 0;
        for (int i = 0; i < k; ++i)
        {
            if (s[i] != e[i])
            {
                c++;
                if (c > 1)
                {
                    return false;
                }
            }
        }
        return c==1;
    }

    int[] dijstra(int begin, int[][] dis, int n, const int MAX) {
        int distance[] = new int[n];
        memset(distance, sizeof(distance), MAX);

        stack<string> s;
        s.push(begin);
        distance[begin] = 0;
        while(!s.empty())
        {
            int cur = s.top();
            s.pop();

            for (int i = 0; i < n+2 && i!=cur; ++i)
            {
                if (dis[cur][i] == 1)
                {
                    distance[i] = min(distance[i], distance[cur] + 1);
                    s.push(i);
                }
            }
        }
    }

    int min(int a, int b) {
        return a>b?b:a;
    }

};

int main()
{
    //Solution* s = new Solution();
    //s->func();
    Solution s;
    string start, end;
    cin >> start >> end;
    vector<string> dict;
    while(cin.get!="\n") {
        string s;
        cin >> s;
        dict.insert(s);
    }

    s.ladderLength("hot", "dot", dict);
    system("PAUSE");
    return 0;
}