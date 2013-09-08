class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        if(n==0)    return 0;
        if(n==1)    return 1;

        int b=0, e=1, max=0;
        set<char> st;
        st.insert(s[b]);
        while(b<=e && e<n) {
            if(st.find(s[e])==st.end()) {

                st.insert(s[e]);
                if(e<n-1)
                    e++;
                int l=st.size();
                if(l>max)   max=l;
            } else {
                if(st.find(s[b])!=st.end())
                    st.erase(st.find(s[b]));
                b++;


            }
        }
        return max;
    }
};