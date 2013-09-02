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

        cout << zero << endl;


        while(1) {
            cout << i << " " << j << endl;
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
                // if (j-1 >= zero)
                // {
                //     j--;
                // }
                // else
                // {
                //     i++;
                // }
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
    int arr[] = {-2,0,1,1,2};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(int));
    vector<vector<int> > out = s.threeSum(v);
    for (vector<vector<int> >::iterator i = out.begin(); i != out.end(); ++i)
    {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j)
        {
            cout << *j << " ";
        }
        cout << endl;

    }

    system("PAUSE");
    return 0;
}



class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        unordered_map<int, vector<int> > hash_map;
        vector<vector<int> > ret;
        for (int i = 0; i != num.size(); ++i) {
            if(hash_map.find(num[i])==num.end()) {
                vector<int> v;
                v.push_back(i);
                hash_map.insert(make_pair(num[i], v));
            } else {
                hash_map[num[i]].push_back(i);
            }

        }
        for(int i=0; i+1<num.size(); ++i) {
            for(int j=i+1; j<num.size(); ++j) {
                int s=num[i]+num[j];
                if(hash_map.find(-s)!=hash_map.end()) {
                    vector<int> v=hash_map.find(-s)->second;
                    for(int k=0; k<v.size(); k++) {
                        if(v[k]>j) {
                            vector<int> r;
                            r.push_back(num[i]);
                            r.push_back(num[j]);
                            r.push_back(num[v[k]]);
                            ret.push_back(r);
                        }
                    }
                }
            }
        }
        ret.resize(unique(ret.begin(), ret.end())-ret.begin());
        return ret;
    }
};