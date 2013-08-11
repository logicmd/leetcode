// TLE
class Solution {
public:

    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1)    return true;
        //if(A[0]==0) return false;
        int *rest_dis = new int[n];
        rest_dis[0] = 0;
        for(int i=1; i<n; i++){
            rest_dis[i] = max(rest_dis[i-1], A[i-1]) - 1;
            if(rest_dis[i]<0)   return false;
        }
        return rest_dis[n-1]>=0;
    }



    bool dfs(int A[], int k, int n) {
        if(k+A[k]>=n)
            return true;
        for(int j=A[k];j>0;j--)
            if(dfs(A, k+j, n))
                return true;
        return false;
    }




    bool TLEDFScanJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1)    return true;
        for(int i=0; i<n; i++) {
            if (dfs(A, i))
                return true;
        }
        return false;
    }

    bool TLEcanJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1)    return true;
        bool *f=new bool[n];
        f[0]=true;
        for(int i=0; i<n; i++) {
            if(f[i]) {
                for(int j=1;j<=A[i];j++) {
                    f[i+j]=true;
                }
            } else {
                break;
            }
        }
        return f[n-1];
    }
};