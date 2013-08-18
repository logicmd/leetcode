class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(dividend==0) return 0;
        long long d=0;
        long long dd=dividend, dr=divisor;
        if(dd*dr<0) {
            if(dd<0)
                dd=-dd;
            else
                dr=-dr;
        } else {
            if(dr<0) {
                dr=-dr;
                dd=-dd;
            }
        }

        if(dr==1)  return dd;

        while(dd>0) {
            dd-=dr;
            d++;
        }

        return (int)d;
    }
};