#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <unordered_map>


using namespace std;

// AC
// Java更新map，hashmap.put(key, new_value)，新的value就会被overwritten了
// C++不一样，hash_map.emplace(key, new_value)不会有用，得hash_map[key]=new_value


class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        unordered_map<string, int> hash_map;
        unordered_map<string, string> word_map;
        for (vector<string>::iterator i = strs.begin(); i != strs.end(); ++i)
        {
            multiset<char> s;
            string str;
            if ((*i).size() > 0)
            {
                for (int j = 0; j < (*i).size(); ++j)
                {
                    s.insert((*i)[j]);
                }
                for (multiset<char>::iterator j = s.begin(); j != s.end(); ++j)
                {
                    str.push_back(*j);
                }
                //cout << str << endl;
            }
            word_map.emplace(*i, str);
            unordered_map<string, int>::iterator got = hash_map.find(str);
            if (got == hash_map.end())
            {
                hash_map.emplace(str, 1);
            }
            else
            {
                hash_map[str] = got->second + 1;
            }
        }
        //cout << word_map.size() << endl;
        // cout << hash_map.size() << endl;

        // for (unordered_map<string, int>::iterator i = hash_map.begin(); i != hash_map.end(); ++i)
        // {
        //     cout << i->first << ": " << i->second << endl;
        // }

        vector<string> ret;
        for (vector<string>::iterator i = strs.begin(); i != strs.end(); ++i)
        {
            multiset<char> s;
            string str = word_map.find(*i)->second;
            if (hash_map.find(str)->second > 1)
            {
                ret.push_back(*i);
            }
        }


        return ret;

    }
};

int main()
{
    Solution s;

    string strin[49] = {"hos","boo","nay","deb","wow","bop","bob","brr","hey","rye","eve","elf","pup","bum","iva","lyx","yap","ugh","hem","rod","aha","nam","gap","yea","doc","pen","job","dis","max","oho","jed","lye","ram","pup","qua","ugh","mir","nap","deb","hog","let","gym","bye","lon","aft","eel","sol","jab"};
    vector<string> vin(strin, strin + 49);
    vector<string> vout = s.anagrams(vin);
    for (vector<string>::iterator i = vout.begin(); i != vout.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    system("PAUSE");
    return 0;
}