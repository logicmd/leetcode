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
//AC
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(S=="" || T=="")  return "";
        unordered_map<char,int> TT;
        for(int i=0; i<T.size(); i++) {
            if(TT.find(T[i])==TT.end())
                TT.insert(make_pair(T[i],1));
            else
                TT[T[i]]++;
        }

        int s=0, e=0;
        int min=(1<<30)-1+(1<<30);
        string str;
        while(s<=e) {
            if(!is_matched(TT)) {
                if(TT.find(S[e])!=TT.end())
                    TT[S[e]]--;
                //cout << S.size() << endl;
                if(e<S.size())
                    e++;
                else
                    break;
                //cout << e << endl;
            } else {
                if(TT.find(S[s])!=TT.end())
                    TT[S[s]]++;

                if(e-s<min) {
                    min=e-s;
                    //cout << s << " " << min << endl;
                    str=S.substr(s,min);

                }
                s++;

            }
        }
        return str;
    }

    bool is_matched(unordered_map<char, int>& TT) {
        for(unordered_map<char, int>::iterator its=TT.begin(); its!=TT.end(); its++) {
            if(its->second>0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    cout << s.minWindow("a", "a")<< endl;

}
