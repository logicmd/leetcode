// reverse
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = m-1;
        int j = n-1;
        int k = i+j;
        while(i>=0 && j>=0 && k>=0) {
            while(A[i]>B[j]) {

                A[k] = A[i];
                i--;
                k--;
            }

            while(A[i]<=B[j]) {

                A[k] = B[j];
                j--;
                k--;
            }
        }
    }
};