class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        while(n>0) {
            v.insert(v.begin(), n%10);
            n/=10;
        }
        string s;
        int times = 0;
        int digit = -1;
        for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        {
            if(*i != digit) {
                if(digit != -1) {
                    s.insert(s.begin(), digit);
                    s.insert(s.begin(), digit);

                }

                times = 1;
                digit = *i;
            } else {
                times++;
            }
        }
        if(times!=0) {
            s.insert(s.begin(), times);
            s.insert(s.begin(), digit);
        }


        return s;
    }
};