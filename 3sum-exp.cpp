#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_set>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;
template <typename Container>
struct container_hash  {
    std::size_t operator()(Container const& c) const {
        std::size_t seed = 0;
        for (Container::iterator i = c.begin(); i != c.end(); ++i)
        {
            seed ^= hash(*i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        sort(num.begin(), num.end());
        unordered_set<vector<int>,  container_hash<vector<int> > > hashset;

        int i = 0, j = n - 1;
        int zero = 0;
        while(zero < n) {
            if (num[zero] == 0)
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
            if (num[i] + num[j] > 0)
            {
                for (int z = zero; z > i; --z)
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
            }
            if (num[i] + num[j] < 0)
            {
                for (int z = zero; z < j; ++z)
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
            }
        }

        vector<vector<int> > vv;
        for (unordered_set<vector<int> >::iterator it = hashset.begin(); it != hashset.end(); ++it)
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