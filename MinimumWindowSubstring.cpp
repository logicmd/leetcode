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
        int min=1<<31-1;
        string str;
        while(s<=e) {
            if(!is_matched(TT)) {
                if(TT.find(S[e])!=TT.end())
                    TT[S[e]]--;
                if(e<S.size())
                    e++;
                else
                    break;
            } else {
                if(TT.find(S[s])!=TT.end())
                    TT[S[s]]++;
                s++;
                if(e-s+1<min) {
                    min=e-s+1;
                    str=str.substr(s,min);
                }

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