class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0)    return 1.0;
        if(x==0.0)  return 0.0;
        if(x==1.0)  return 1.0;
        if(x==-1.0) return 1.0-2*(abs(n)%2);
        double r=1.0;
        if(n>0) {
            while(n--){
                r*=x;
                if(r==0.0)
                    return 0.0;
            }
            return r;
        } else {
            n=-n;
            while(n--){
                r/=x;
                if(r==0.0)
                    return 0.0;
            }
            return r;
        }

    }
};