class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string c;
        int m = a.size();
        int n = b.size();
        int max,min;
        string longstr;
        if(m>n) {
            longstr=a;
            min = n;
            max = m;
        } else {
            longstr=b;
            min = m;
            max = n;
        }
        int overflow = 0;
        for(int i=0; i<min; ++i) {
            int aa=a[m-1-i]-'0';
            int bb=b[n-1-i]-'0';
            int cc=aa+bb+overflow;
            if(cc>1)
                overflow=1;
            else
                overflow=0;
            cc%=2;
            c.insert(c.begin(),cc+'0');
        }

        string overhead;

        for(int i=min;i<max;i++) {
            int ss=longstr[max-1-i]-'0';
            ss+=overflow;
            if(ss>1)
                overflow=1;
            else
                overflow=0;
            ss%=2;
            overhead.insert(overhead.begin(),ss+'0');
        }



        c.insert(0,overhead);

        if(overflow==1)
            c.insert(c.begin(),'1');

        return c;

    }

};
