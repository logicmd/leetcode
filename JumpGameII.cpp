// TLE
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1)    return 0;
        if(A[0]==0) return 1<<31-1;

        int *step = new int[n];
        A[n-1]=0;
        for(int i=n-2; i>=0; i--) {
            if(A[i]>=n-i-1) {
                step[i] = 1;
            } else {
                int min = 1<<31-1;
                for(int j=1; j<=A[i] && j<n; j++) {
                    if(min>step[i+j])
                        min=step[i+j];
                }
                step[i]=min+1;
            }
        }

        return step[0];
    }
};