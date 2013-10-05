class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0 || n==1)
            return 0;
        int *left=new int[n];
        left[0]=A[0];
        for(int i=1; i<n; i++)
            left[i]=max(left[i-1],A[i]);
        int *right=new int[n];
        right[n-1]=A[n-1];
        for(int i=n-2; i>=0; i--)
            right[i]=max(right[i+1],A[i]);
        int sum=0;
        for(int i=0; i<n; i++) {
            int m=min(left[i], right[i]);
            if(m>A[i])
                sum+=(m-A[i]);
        }
        return sum;
    }
};