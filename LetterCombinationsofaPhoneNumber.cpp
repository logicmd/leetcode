class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;

        string map[] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        bool flag = false;
        for(int i=0; i<digits.size(); i++) {
            int d=digits[i]-'0';
            if(d>=2 && d<=9) {
                string can = map[d];
                if(flag) {
                    vector<string> tmp;
                    vector<string>().swap(tmp);
                    tmp.swap(ret);
                    for (vector<string>::iterator k = tmp.begin(); k != tmp.end(); ++k)
                    {
                        string ss=*k;
                        for(int j=0; j<can.size(); j++) {
                            string sss=ss;
                            sss.insert(sss.end(),can[j]);
                            ret.push_back(sss);
                        }
                    }
                } else {
                    for(int j=0; j<can.size(); j++) {
                        string sss;
                        sss.insert(sss.end(),can[j]);
                        ret.push_back(sss);
                    }
                    flag=true;
                }

            }
        }
        if(ret.size()==0)   ret.push_back("");
        return ret;
    }
};