class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> hashmap;
        int n = T.size();
        for(int i=0; i<n; i++) {
            map<char,int>::iterator got = hashmap.find(T[i]);
            if(got != hashmap.end()) {
                hashmap[T[i]]++;
            } else {
                hashmap.insert(make_pair(T[i], 0));
            }
        }
    }
};