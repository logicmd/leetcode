class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r=0;
        int last=0;
        while(*s) {
            if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
                r++;
            } else {
                if(r!=0)    last = r;
                r=0;
            }
            s++;
        }
        if(r==0)    return last;
        else    return r;

    }
};