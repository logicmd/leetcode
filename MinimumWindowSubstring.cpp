class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(S=="" || T=="")  return "";
        unordered_map<string,int> TT;
        for(int i=0; i<T.size(); i++) {
            TT.insert(make_pair(T[i],1));
        }

        int s=0, e=1;



    }
};