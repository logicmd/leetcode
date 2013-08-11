class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* max = new int[n];
        if(A[0]<0)  max[0]=0;
        else    max[0]=A[0];
        for(int i=1; i<n; i++) {
            max[i]=max[i-1]+A[i];
            if(max[i]<0)    max[i]=0;
        }
        int ret = max[0];
        for(int i=0; i<n; i++) {
            if(ret<max[i])    ret=max[i];
        }

        if(ret==0) {
            int max_neg = 0-1<<31;
            for(int i=0; i<n; i++) {
                if(A[i]==0)
                    return 0;
                else {
                    if(A[i]>max_neg)
                        max_neg = A[i];
                }
            }
            ret = max_neg;
        }
        return ret;
    }
};