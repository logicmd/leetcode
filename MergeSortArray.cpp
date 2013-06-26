// reverse
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = m-1;
        int j = n-1;
        int k = i+j;
        while(i>=-1 && j>=-1 && k>=0) {
            while(i>=0 && ((j>=0 && A[i]>B[j]) || j==-1) ) {

                A[k] = A[i];
                i--;
                k--;
            }

            while(j>=0 && ((i>=0 && A[i]<=B[j]) || i==-1 ) {

                A[k] = B[j];
                j--;
                k--;
            }
        }
    }
};