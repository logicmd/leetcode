class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=2)
            return n;
            
        
        vector<int> s;
        s.push_back(A[0]);
        s.push_back(A[1]);
        int len=2;
        
        for(int i=2; i<n; i++) {
            if(A[i] == A[i-1] && A[i] == A[i-2]) {
                continue;
            }
            s.push_back(A[i]);
            len++;
        }
        int j=0;
        for(vector<int>::iterator it=s.begin(); it!=s.end(); it++) {
            A[j]=*it;
            j++;
        }
        return len;
        
    }
};
