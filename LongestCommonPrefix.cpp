class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min=1<<31-1;
        int min_i=0;
        for (int i=0; i<strs.size(); ++i) {
            if(strs[i].size()<min) {
                min=strs[i].size();
                min_i=i;
            }
        }
        string ret;
        for(int j=0; j<min; j++) {
            char c=strs[min_i][j];
            for (int i=0; i<strs.size(); ++i) {
                if(strs[i][j]!=c) {
                    return ret;
                }
            }
            ret.push_back(c);
        }
    }
};