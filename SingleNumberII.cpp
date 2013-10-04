class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int count[32];

        int res=0;
        for(int i=0; i<32; i++) {
            count[i]=0;
            for(int j=0; j<n; j++) {
                count[i]+=((A[j]>>i)%2);
            }
            if(count[i]%3!=0) {
                res+=(1<<i);
            }
        }
        return res;
    }
};