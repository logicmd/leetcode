class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> st;
        int m=-1;
        for(int i=0; i<height.size(); i++) {
            if(st.empty() || height[i]>=height[st.peek()]) {
                st.push(i);
            } else {
                int j=st.peek();
                st.pop();
                int area=(i-j+1)*num[j];
                if(area>m)
                    m=area;
            }
        }
        return m;
    }
};