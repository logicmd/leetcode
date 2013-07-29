// "110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000"    

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long aa=0;
        for(int i=0; i<a.size(); i++) {
            if(a[i]=='1') aa++;
            aa<<=1;
        }
        aa>>=1;
        
        long long bb=0;
        for(int i=0; i<b.size(); i++) {
            if(b[i]=='1') bb++;
            bb<<=1;
        }
        bb>>=1;
        
        long long cc=aa+bb;
        if(cc==0)
            return "0";
        string c;
        while(cc>0) {
            if(cc%2==1)
                c.insert(c.begin(),'1');
            else
                c.insert(c.begin(),'0');
            cc>>=1;
        }
        return c;
        
    }

};
