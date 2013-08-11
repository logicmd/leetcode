#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=num2.size();
        int n=num1.size();
        string *sum = new string[m];
        if(num1=="0" || num2=="0")   return "0";
        for(int i=m-1; i>=0; i--) {

            if(num2[i]=='0')
                sum[i]="0";
            else {
                int add=0;
                for(int j=n-1; j>=0; j--) {
                    int mul = (num2[i]-'0')*(num1[j]-'0')+add;
                    int digit = mul%10;
                    add = mul/10;
                    sum[i].insert(sum[i].begin(), digit+'0');
                }
                if(add>0)
                    sum[i].insert(sum[i].begin(), add+'0');

                for(int k=0; k<m-1-i; k++) {
                    sum[i].insert(sum[i].end(), '0');
                }
            }

        }

        string ret = sum[0];

        for(int i=1; i<m; i++) {
            ret = add_ops(ret, sum[i]);
        }

        return ret;

    }


    string add_ops(string a, string b) {
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
            overflow = cc/10;
            cc%=10;
            c.insert(c.begin(),cc+'0');
        }
        string overhead;


        for(int i=min;i<max;i++) {
            int ss=longstr[max-1-i]-'0';
            ss+=overflow;
            overflow = ss/10;
            ss%=10;

            overhead.insert(overhead.begin(),ss+'0');
        }



        c.insert(0,overhead); // insert string and insert char is totally different

        if(overflow>0)
            c.insert(c.begin(),overflow+'0');


        return c;
    }
};

int main() {
    string a = "140";
    string b = "721";
    Solution s;
    //cout << s.add_ops("2800","98000") << endl;
    cout << s.multiply(a, b) << endl;
    system("PAUSE");
}