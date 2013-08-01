// TLE
class Solution {
public:
    bool dfs(int A[], int k, int n) {
        if(k+A[k]>=n)
            return true;
        for(int j=A[k];j>0;j--)
            if(dfs(A, k+j, n))
                return true;
        return false;
    }


    bool canJump(int A[], int n) {
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