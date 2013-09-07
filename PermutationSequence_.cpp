//AC
class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1)    return "1";
        string s="1";
        int frac=1;
        for(int i=1; i<=n-1; ++i) {
            frac*=i;
            s.insert(s.end(), '1'+i);
        }

        for(int i=n-1; i>=0; --i) {
            int t=k/frac;
            if(k%frac==0)   t--;
            char c=s[n-1-i+t];
            s.erase(s.begin()+(n-1-i+t));
            s.insert(s.begin()+(n-1-i),c);

            k-=t*frac;
            if(i!=0)
                frac/=i;
        }
        return s;
    }
};