class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(dict.size()==0) return false;
        if(start.size()!=end.size()) return false;
        if(start.size()==0 || end.size()==0)    return false;

        queue<string> in, out;
        in.push(start);
        int c=1;
        while(!in.empty() && !out.empty()) {
            while(!in.empty()) {
                string cur=in.front();
                in.pop();
                for(unordered_set<string>::iterator its=dict.begin(); its!=dict.end(); its++) {
                    if(isConnect(cur, *its)) {
                        if(isConnect(end, *its)) {
                            c++;
                            return c;
                        }
                        dict.erase(its);
                        out.push(*its);
                    }
                }
            }
            ++c;
            swap(in, out);
            queue<string>().swap(out);

        }
        return 0;

    }

    bool isConnect(string s, string e) {
        if(s.size()!=e.size())  return false;
        int n=s.size();
        int c = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != e[i])
            {
                c++;
                if (c > 1)
                {
                    return false;
                }
            }
        }
        return c==1||c==0;
    }
};