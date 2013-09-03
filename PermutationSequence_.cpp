class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1)    return "1";
        int frac=1;
        for(int i=1; i<=n-1; ++i) {
            frac*=i;
        }

        string s;
        for(int i=n-1; i>=0; --i) {
            int t=k%frac;
            char c=t+'1';
            s.insert(s.begin(), c);
            k-=t*frac;
            if(i!=0)
                frac/=i;
        }
        return s;
    }
};