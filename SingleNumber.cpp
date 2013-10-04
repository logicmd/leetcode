class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0) {
            return 0;
        }
        int k=A[0];
        for(int i=1; i<n; i++) {
            k^=A[i];
        }
        return k;
    }
};