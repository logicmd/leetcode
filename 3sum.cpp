#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_set>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();

        if (n<3)
        {
            vector<vector<int> > noth;
            return noth;
        }
        if (!is_sorted(num.begin(), num.end()))
        {
            sort(num.begin(), num.end());
        }

        set<vector<int> > hashset;

        int i = 0, j = n - 1;
        int zero = 0;
        while(zero < n) {
            if (num[zero] >= 0)
            {
                break;
            }
            zero++;
        }

        while(1) {
            if (i >= j)
            {
                break;
            }
            if (num[i] + num[j] + num[i] > 0)
            {
                j--;
                continue;
            }
            if (num[i] + num[j] + num[j] < 0)
            {
                i++;
                continue;
            }
            if (num[i] + num[j] == 0)
            {
                int z = zero;
                while (z <= i)
                {
                    z++;
                }
                if (z < j && num[z] == 0)
                {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[z]);
                    v.push_back(num[j]);

                    hashset.insert(v);
                }
                i++;
                continue;
            }
            if (num[i] + num[j] > 0)
            {
                for (int z = zero - 1; z > i; --z)
                {
                    if (num[i] + num[j] + num[z] == 0)
                    {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[z]);
                        v.push_back(num[j]);

                        hashset.insert(v);
                        break;
                    }
                }
                j--;
                continue;
            }
            if (num[i] + num[j] < 0)
            {
                for (int z = zero + 1; z < j; ++z)
                {
                    if (num[i] + num[j] + num[z] == 0)
                    {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[z]);
                        v.push_back(num[j]);

                        hashset.insert(v);
                        break;
                    }
                }
                i++;
                continue;
            }
        }

        vector<vector<int> > vv;
        for (set<vector<int> >::iterator it = hashset.begin(); it != hashset.end(); ++it)
        {
            vv.push_back(*it);
        }
        return vv;
    }
};

int main()
{
    Solution s;

    system("PAUSE");
    return 0;
}