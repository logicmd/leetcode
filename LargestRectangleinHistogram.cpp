//WA
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> st;
        int m=0;
        for(int i=0; i<height.size(); i++) {
            if(st.empty() || height[i]>=height[st.top()]) {
                st.push(i);
            } else {
                while(!st.empty() && height[st.top()]>height[i]) {
                    int j=st.top();
                    st.pop();
                    int area=(i-j)*height[j];
                    if(area>m)
                        m=area;
                }
                st.push(i);
            }
        }
        if(!st.empty()) {
            int ind=st.top()+1;
            while(!st.empty()) {
                int j=st.top();
                st.pop();
                int area=(ind-j)*height[j];
                if(area>m)
                    m=area;
            }
        }

        return m;
    }
};