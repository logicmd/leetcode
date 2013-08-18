class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s=0;
        int e=n-1;
        int m=(s+e)/2;
        while (s<e) {
            if(target<A[m]) {
                e=m-1;
                m=(s+e)/2;
            } else if(target>A[m]) {
                s=m+1;
                m=(s+e)/2;
            } else {
                return m;
            }
        }
        if(target>A[s]) return s+1;
        else    return s;

    }
};