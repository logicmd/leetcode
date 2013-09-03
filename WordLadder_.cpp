#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(dict.size()==0) return false;
        if(start.size()!=end.size()) return false;
        if(start.size()==0 || end.size()==0)    return false;


        queue<string> in, out;
        in.push(start);
        int c=1;
        while(!in.empty() && !dict.empty()) {
            while(!in.empty()) {

                string org=in.front();
                string cur=org;
                in.pop();
                for(int i=0; i<cur.size(); i++) {

                    char tmp=cur[i];
                    for(int j=0; j<'z'-'a'+1; j++) {
                        cur[i]=j+'a';
                        //cout << "0 " << org << "-" << cur << endl;
                        unordered_set<string>::iterator its=dict.find(cur);
                        if(its!=dict.end()) {
                            //cout << "1 " << org << "->" << *its << endl;
                            if(*its==end)
                                return c+1;
                            //if(isConnect(*its, end)) {
                            //  return c+1;
                            //}
                            out.push(*(its));
                            dict.erase(its);
                        }
                    }
                    cur[i]=tmp;

                }
                // for(unordered_set<string>::iterator its=dict.begin(); its!=dict.end();) {
                //     cout << "0 " << cur << "-" << *its << endl;
                //     if(isConnect(cur, *its)) {
                //         cout << "1 " << cur << "->" << *its << endl;
                //         if(isConnect(end, *its)) {
                //             cout << "2 " << *its << "->" << end << endl;
                //             c++;
                //             return c;
                //         }
                //         out.push(*its);
                //         dict.erase(its);
                //         if((its+1)!=dict.end()) {
                //             its++;
                //         }

                //     }
                // }
            }
            ++c;
            swap(in, out);
            queue<string>().swap(out);

        }
        return 0;

    }

    bool isConnect(string s, string e) {
        if(s.size()!=e.size())  return false;
        int n=s.size();
        int c = 0;
        for (int i = 0; i < n; ++i)
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
        return c==1||c==0;
    }
};

int main() {
    string s="a";
    string e="c";
    string dic[] = {"a","b","c"};
    unordered_set<string> dict;
    for(string str:dic) {
        dict.insert(str);
    }
    Solution so;
    cout << so.ladderLength(s, e, dict);
}