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
// TLE
// 字符串匹配常用hash
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> pos;
        if(S=="" || L.size()==0)    return pos;
        int n=L[0].size();
        int m=L.size();
        // S.size() is a unsigned int, fuck
        int s_size=S.size();

        unordered_map<string, int> LL;
        for(int i=0; i<m; i++) {
            if(LL.find(L[i])!=LL.end()) {
                LL[L[i]]++;
            } else {
                LL.insert(make_pair(L[i],1));
            }
        }
        for(int init=0; init<n; init++) {
            bool f=true;
            unordered_map<string,int> s;

            for(int i=init; i<=s_size-m*n; i+=(n)) {
                if(f) {
                    for(int j=0; j<m; j++) {
                        string wd=S.substr(i+n*j,n);
                        if(s.find(wd)!=s.end()) {
                            s[wd]++;
                        } else {
                            s.insert(make_pair(wd,1));
                        }

                    }
                    f=false;
                } else {
                    string wd1=S.substr(i-n,n);
                    s[wd1]--;
                    if(s[wd1]==0) {
                        s.erase(s.find(wd1));
                    }

                    string wd2=S.substr(i+n*(m-1),n);
                    if(s.find(wd2)!=s.end()) {
                        s[wd2]++;
                    } else {
                        s.insert(make_pair(wd2,1));
                    }
                }

                if(isMatched(s,LL)) {
                    pos.push_back(i);
                }
            }
        }

        return pos;

    }

    bool isMatched(unordered_map<string,int> s, unordered_map<string,int> LL) {
        for(unordered_map<string,int>::iterator its=s.begin(); its!=s.end(); its++) {
            string query=its->first;
            if(LL.find(query)!=LL.end() && s.find(query)!=s.end() && its->second==LL[query]) {
                ;
            } else {
                return false;
            }
        }
        return true;
    }

    bool isMatched_(vector<string> s, unordered_map<string,int> LL) {
        for(int i=0; i<s.size(); ++i) {
            if(LL.find(s[i])!=LL.end()) {
                if(--LL[s[i]]<0) {
                    return false;
                }
            } else {
                return false;
            }
        }

        for(unordered_map<string,int>::iterator its=LL.begin(); its!=LL.end(); its++) {
            if(its->second!=0)
                return false;
        }
        return true;
    }

    bool isMatchedold(vector<string> s, vector<string> t) {
        int m=t.size();
        for(int i=0; i<s.size(); ++i) {
            for(vector<string>::iterator its=t.begin(); its!=t.end(); ++its) {
                if(s[i]==(*its)) {
                    t.erase(its);
                    break;
                }
            }
            if(t.size()==m-1) {
                m=t.size();
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    string S="aaa";
    vector<string> L;
    L.push_back("a"); L.push_back("a");
    vector<int> re=s.findSubstring(S,L);
    for(vector<int>::iterator its=re.begin(); its!=re.end(); ++its) {
        cout << *its << endl;
    }
    return 0;
}