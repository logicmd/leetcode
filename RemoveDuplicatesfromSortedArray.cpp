class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0)   return 0;
        int j = 0;
        for(int i = 0; i < n-1; i++) {
            if (A[i] != A[i+1])
            {
                A[j++] = A[i];
            }
        }
        A[j++]=A[n-1];

        return j;
    }
};